CP_TEMPLATE_DIR=~/workspace/Algo/CompetitiveProgramming/CP

prepare_cp() {
    cp "${CP_TEMPLATE_DIR}/solve.cpp" ./solve.cpp
    mkdir -p build .vscode

    cat > .gitignore << 'EOF'
build/
.gitignore
Makefile
.vscode/
solve.cpp
EOF

    cat > Makefile << 'EOF'
CXX      = g++
VERSION  = c++23
TARGET   = solve
CXXFLAGS = -std=$(VERSION) -g -DDEBUG -Wall -Wextra

.PHONY: build/debug_bin
build/debug_bin:
	$(CXX) $(CXXFLAGS) -o build/debug_bin $(TARGET).cpp
EOF

    cat > .vscode/tasks.json << 'EOF'
{
  "version": "2.0.0",
  "tasks": [
    {
      "label": "Build Debug",
      "type": "shell",
      "command": "make",
      "args": ["build/debug_bin"],
      "group": { "kind": "build", "isDefault": true },
      "problemMatcher": []
    }
  ]
}
EOF

    cat > .vscode/launch.json << 'EOF'
{
  "version": "0.2.0",
  "configurations": [
    {
      "name": "Debug",
      "type": "lldb",
      "request": "launch",
      "program": "${workspaceFolder}/build/debug_bin",
      "preLaunchTask": "Build Debug",
      "terminal": "integrated"
    }
  ]
}
EOF

    echo "Done."
}