---
layout: default
course_number: CS335
title: Lab - Cross-Site Request Forgery Attack
---

# Lab - Cross-Site Request Forgery (CSRF) Attack Lab

### Lab Description and Tasks

- Lab Description: [CSRF Attack Lab.pdf](csrf\Web_CSRF_Elgg.pdf)
- Lab Setup files: [Labsetup.zip](csrf\Labsetup.zip)

- Make sure you answer the questions under Task 3.
- You **must provide a screenshot** of the network traffic with each attack. Any tool is acceptable:
   - Wireshark
   - Browser Developer Tools
   - HTTP Header Live

#### Login information

User | User Name | Password
-----|----------|---------
Admin | admin | seedelgg
Alice | alice | seedalice
Boby | boby | seedboby
Charlie | charlie | seedcharlie
Samy | samy | seedsamy

### References

 - [Firefox Developer Tools](https://developer.mozilla.org/en-US/docs/Tools)
 - [HTTP Header Live](https://addons.mozilla.org/en-US/firefox/addon/http-header-live/) Displays the HTTP header. Edit it and send it.
 - The HTML &lt;form&gt; Element [Reference](https://developer.mozilla.org/en-US/docs/Web/HTML/Element/form)
 - [SameSite](https://developer.mozilla.org/en-US/docs/Web/HTTP/Headers/Set-Cookie/SameSite) Cookies
 - [Cross-Site Request Forgery Prevention Cheat Sheet](https://cheatsheetseries.owasp.org/cheatsheets/Cross-Site_Request_Forgery_Prevention_Cheat_Sheet.html)
 - 
### Examples
- [https://hackerone.com/reports/834366](https://hackerone.com/reports/834366)
- [https://hackerone.com/reports/204703](https://hackerone.com/reports/204703)
- [https://hackerone.com/reports/127703](https://hackerone.com/reports/127703/)
- [https://hackerone.com/reports/157993](https://hackerone.com/reports/157993/)
- [https://hackerone.com/reports/111216](https://hackerone.com/reports/111216)

### Grading

Post your report in [Marmoset](https://cs.ycp.edu/marmoset) by the scheduled due date in the syllabus. Your grade for this lab will be composed of:
- 30% - Design
- 30% - Observations
- 40% - Explanation
- *Extra Credit* if you pursue further investigation, beyond what is required by the lab description.
