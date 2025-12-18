#!/bin/bash

# Test script for chess program

# Colors for output
RED='\033[0;31m'
GREEN='\033[0;32m'
YELLOW='\033[1;33m'
NC='\033[0m' # No Color

dir=$(dirname "$0")
chess="${dir}/chess"

# Check if chess executable exists
if [ ! -f "$chess" ]; then
    echo -e "${RED}Error: chess executable not found at $chess${NC}"
    exit 1
fi

echo -e "${YELLOW}Testing chess program...${NC}\n"

# Create test input
cat << 'EOF' | $chess
Ke1e2
print
Ke1f1
Pe2e3
pe7e6
print
Ke1e2
print
ke8e7
Ke2f3
ke7d6
Kf3e4
kd6e5
print
Ke4e5
Ke4f5
ke5e4
Kfe5
print
Kf5xe4
print
undo
print
Kf5f3
Kf5h5
print
Kf5h4
print
Kf5h3
print
EOF

echo -e "\n${GREEN}Test completed${NC}"