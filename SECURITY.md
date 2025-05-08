# Security Policy for CPCD

The CPCD team and community take the security of our software seriously. We appreciate your efforts to responsibly disclose your findings, and we will make every effort to address any issues in a timely manner.

## Supported Versions

We are committed to providing security updates for the following versions of CPCD:

| Version | Supported          |
| ------- | ------------------ |
| 0.1.x   | :white_check_mark: |
| < 0.1.0 | :x: (Unsupported)  |

As new major or minor versions are released, support for older versions may be phased out. Please always try to use the latest stable version of CPCD.

## Reporting a Vulnerability

If you discover a security vulnerability in CPCD, please report it to us privately to give us an opportunity to fix it before it is publicly disclosed. This helps protect our users.

**Please do NOT report security vulnerabilities through public GitHub issues.**

Instead, please send an email to:
`bezart06@gmail.com`

When reporting a vulnerability, please try to include the following information:

* **A clear description of the vulnerability:** What is the vulnerability and what is its potential impact?
* **Steps to reproduce:** Provide detailed steps on how to reproduce the vulnerability. This is crucial for us to verify and fix the issue.
* **Affected version(s):** Specify which version(s) of CPCD are affected.
* **Your environment:** Details about your operating system, version, and any other relevant configuration.
* **Proof-of-concept (PoC):** If possible, provide a PoC or code snippet that demonstrates the vulnerability.

We will acknowledge receipt of your vulnerability report within 72 hours and will work with you to understand and validate the issue. We aim to keep you informed of our progress.

Once a vulnerability is confirmed and a fix is developed, we will coordinate with you on the disclosure timeline. We typically aim to release a fix as soon as possible.

## Security Considerations for CPCD

CPCD interacts with the operating system at a low level to manage input (keyboard hooks) and display (full-screen mode). This has several security implications:

* **Input Blocking:** The core functionality of CPCD is to block keyboard input. While this is intended for focus or specific control scenarios, any bypass or unintended behavior of this mechanism could be a concern.
* **Elevated Privileges (Potentially):** Depending on the specific actions performed (e.g., setting system-wide hooks, blocking certain system key combinations in future versions), CPCD or parts of it might require elevated privileges to run. Running applications with elevated privileges should always be done with caution. We aim to minimize the need for such privileges wherever possible.
* **Safe Exit Mechanism:** The current safe exit mechanism (Right Ctrl + Right Alt) is hardcoded. Future versions aim to make this customizable. The security and robustness of this exit mechanism are important.

## Development Best Practices

While CPCD is currently a small project, we strive to follow security best practices in our development process, including:

* **Code Review:** Pull requests are encouraged and will be reviewed for potential security issues before merging (as the community grows).
* **Dependency Management:** We aim to use well-maintained libraries and keep dependencies up-to-date (currently, the project has minimal external dependencies beyond standard C++ and OS APIs).
* **Least Privilege:** We design features with the principle of least privilege in mind, requesting only the necessary permissions for the application to function.
* **Static Analysis:** We may incorporate static analysis tools in the future to help identify potential vulnerabilities in the codebase.

## Scope

This security policy applies to the CPCD application itself. It does not cover:
* The security of the operating systems it runs on (Windows, and Linux in the future).
* The security of third-party tools used for development (e.g., CMake, compilers, Git).
* Security issues in dependencies that are outside our direct control (though we will endeavor to update or mitigate known issues).
