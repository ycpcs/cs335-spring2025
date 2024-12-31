---
layout: default
course_number: CS335
title: Lab - SQL Injection Lab
---

# Lab - SQL Injection Attack Lab

### Lab Description and Tasks

- Lab Description: [SQL Injection.pdf](sqli\Web_SQL_Injection.pdf)
- Lab Setup Files: [Labsetup.zip](sqli\Labsetup.zip)

Additional information on the SEED project [site](https://seedsecuritylabs.org/Labs_20.04/Web/Web_SQL_Injection/).

[Bobby Tables](https://bobby-tables.com/): A guide to preventing SQL injection
[SQL Injection Prevention](https://cheatsheetseries.owasp.org/cheatsheets/SQL_Injection_Prevention_Cheat_Sheet.html)

#### Login information

User |  Password
-----|---------
admin | seedadmin
alice | seedalice
boby | seedboby
ryan | seedryan
ted | seedted
samy | seedsamy

### Tips

- Multiple ways to generate SHA1 of a password:
  - ```mysql> select sha1('new_password');```
  - [CyberChef](https://gchq.github.io/CyberChef/) and search for SHA1

### Examples
- [https://hackerone.com/reports/150156/](https://hackerone.com/reports/150156/)
- [https://hackerone.com/reports/31756/](https://hackerone.com/reports/31756/)

### Grading

Post your report in [Marmoset](https://cs.ycp.edu/marmoset) by the scheduled due date in the syllabus. Your grade for this lab will be composed of:
- 30% - Design
- 30% - Observations
- 40% - Explanation
- *Extra Credit* if you pursue further investigation, beyond what is required by the lab description.
