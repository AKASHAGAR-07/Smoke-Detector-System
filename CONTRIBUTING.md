# Contributing to Smoke Detector System

Thank you for your interest in contributing to the **Smoke Detector System** project! This repository represents a completed final-year Electronics and Communication Engineering STEM project. We welcome academic contributions, improvements, and bug fixes.

## Code of Conduct

Please be respectful and professional in all communications and contributions. This project aims to maintain high academic and engineering documentation standards.

## How Can I Contribute?

### Reporting Bugs or Feedback
If you find any bugs in the code, inconsistencies in the documentation, or errors in the circuit diagram descriptions:
1. Search the existing Issues to see if it has already been reported.
2. Open a new issue with a clear title and description of the issue, along with steps to reproduce it.

### Submitting Pull Requests (PRs)
1. Fork the repository.
2. Create a new branch for your feature or bug fix:
   ```bash
   git checkout -b feature/your-feature-name
   ```
3. Make your changes. Ensure your Arduino code is properly commented and adheres to the style guide.
4. Update the relevant documentation if you add features, change hardware pins, or update simulation setups.
5. Commit your changes with clear, descriptive commit messages:
   ```bash
   git commit -m "docs: update pin layout table for LCD module"
   ```
6. Push to your fork and submit a Pull Request.

## Code Style Guide

- **Arduino/C++ Code**:
  - Use camelCase for variables and function names.
  - Use UPPER_SNAKE_CASE for constants and pin definition macros.
  - Keep indentations clean (4 spaces or 1 tab).
  - Include comments explaining the purpose of each function block, especially when interfacing with sensors, LCDs, and actuators.
  - Define all constants and Pin assignments at the top of the file.

- **Documentation (Markdown)**:
  - Maintain a clean hierarchy with proper heading levels (`#`, `##`, `###`).
  - Use bullet points and tables for lists and technical specifications.
  - Link files using standard Markdown formatting.

## Licensing

By contributing to this project, you agree that your contributions will be licensed under the project's **MIT License**.
