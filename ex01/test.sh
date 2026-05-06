#!/usr/bin/env bash

EXEC=./phonebook
PASS=0
FAIL=0

# Color codes
GREEN='\033[0;32m'
RED='\033[0;31m'
NC='\033[0m' # no color

# Run the binary with stdin and capture output
run() {
    echo "$1" | $EXEC 2>&1
}

# Assert output contains a string
assert_contains() {
    local test_name="$1"
    local output="$2"
    local expected="$3"
    if echo "$output" | grep -qF "$expected"; then
        echo -e "${GREEN}  PASS${NC} $test_name"
        ((PASS++))
    else
        echo -e "${RED}  FAIL${NC} $test_name"
        echo "       expected to find: '$expected'"
        echo "       got output:"
        echo "$output" | sed 's/^/         /'
        ((FAIL++))
    fi
}

# Assert output does NOT contain a string
assert_not_contains() {
    local test_name="$1"
    local output="$2"
    local unexpected="$3"
    if echo "$output" | grep -qF "$unexpected"; then
        echo -e "${RED}  FAIL${NC} $test_name (unexpected text found)"
        echo "       should not contain: '$unexpected'"
        ((FAIL++))
    else
        echo -e "${GREEN}  PASS${NC} $test_name"
        ((PASS++))
    fi
}

# Assert exit code
assert_exit() {
    local test_name="$1"
    local actual="$2"
    local expected="$3"
    if [ "$actual" -eq "$expected" ]; then
        echo -e "${GREEN}  PASS${NC} $test_name (exit $actual)"
        ((PASS++))
    else
        echo -e "${RED}  FAIL${NC} $test_name"
        echo "       expected exit $expected, got $actual"
        ((FAIL++))
    fi
}

# ─────────────────────────────────────────────
echo "=== Test 1: Basic Add + Search ==="
OUT=$(run "$(printf 'ADD\nJohn\nDoe\nJD\n123456789\nMy first contact\nADD\nJane\nSmith\nJS\n987654321\nSecond contact\nSEARCH\n1\nEXIT')")
assert_contains "add first contact"  "$OUT" "John"
assert_contains "search returns Doe" "$OUT" "Doe"
assert_contains "phone number shown" "$OUT" "123456789"

# ─────────────────────────────────────────────
echo ""
echo "=== Test 2: Overflow (max 8, 9th replaces oldest) ==="
INPUT=$(printf 'ADD\nA\nA\nAA\n1\nn\nADD\nB\nB\nBB\n2\nn\nADD\nC\nC\nCC\n3\nn\nADD\nD\nD\nDD\n4\nn\nADD\nE\nE\nEE\n5\nn\nADD\nF\nF\nFF\n6\nn\nADD\nG\nG\nGG\n7\nn\nADD\nH\nH\nHH\n8\nn\nADD\nOVER\nFLOW\nOF\n9\nn\nSEARCH\nEXIT')
OUT=$(run "$INPUT")
assert_contains     "9th contact added"  "$OUT" "OVER"
assert_not_contains "oldest evicted"     "$OUT" "AA"   # 'A' should be gone

# ─────────────────────────────────────────────
echo ""
echo "=== Test 3: Invalid index search ==="
OUT=$(run "$(printf 'SEARCH\n999\nEXIT')")
assert_contains "invalid index error" "$OUT" "Index out of range!"  # adjust to match your program's actual message

# ─────────────────────────────────────────────
echo ""
echo "=== Test 4: Empty name fields ==="
OUT=$(run "$(printf 'ADD\n\n\n123\nnote\nSEARCH\n0\nEXIT\nSEARCH\n1')")
assert_contains "empty name handled" "$OUT" "123"   # at least the phone shows up

# ─────────────────────────────────────────────
echo ""
echo "=== Test 5: Exit code check ==="
run "$(printf 'EXIT')" > /dev/null 2>&1
assert_exit "clean exit" $? 0

# ─────────────────────────────────────────────
echo ""
echo "─────────────────────────────────────────"
echo -e "Results: ${GREEN}${PASS} passed${NC}  ${RED}${FAIL} failed${NC}"
[ "$FAIL" -eq 0 ] && exit 0 || exit 1