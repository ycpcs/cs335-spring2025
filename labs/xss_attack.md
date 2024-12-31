---
layout: default
course_number: CS335
title: Lab - Cross-Site Scripting Attack
---

# Lab - Cross-Site Scripting (XSS) Attack Lab

### Lab Description and Tasks

- Lab Description: [XSS Attack Lab.pdf](xss\Web_XSS_Elgg.pdf)
- Lab Setup files: [Labsetup.zip](xss\Labsetup.zip)

Additional information on the SEED project [site](https://seedsecuritylabs.org/Labs_20.04/Web/Web_XSS_Elgg/).

- You *must* provide a screenshot of the network traffic with each attack.

#### Login information

User | User Name | Password
-----|----------|---------
Admin | admin | seedelgg
Alice | alice | seedalice
Boby | boby | seedboby
Charlie | charlie | seedcharlie
Samy | samy | seedsamy

- Example of add a friend script: <a href=".\xss\add-a-friend.txt" target="_blank">add-a-friend.js</a>
- Example of update profile script: <a href=".\xss\update-profile.txt" target="_blank">update-profile.js</a>

### History of Samy's worm
- [The MySpace Worm that Changed the Internet Forever](https://www.vice.com/en_us/article/wnjwb4/the-myspace-worm-that-changed-the-internet-forever)
- [https://samy.pl/myspace/](https://samy.pl/myspace/)
- [Technical explanation of The MySpace Worm](https://samy.pl/myspace/tech.html)
- [Cross-Site Scripting Worm Hits MySpace](https://betanews.com/2005/10/13/cross-site-scripting-worm-hits-myspace/)
- [Cross-Site Scripting Worm Floods MySpace](https://it.slashdot.org/story/05/10/14/126233/cross-site-scripting-worm-floods-myspace)
- Video: [MySpace Worm Animated Story](https://www.youtube.com/watch?v=DtnuaHl378M)

### References
- [Firefox Developer Tools](https://developer.mozilla.org/en-US/docs/Tools)  
- [HTTP Header Live](https://addons.mozilla.org/en-US/firefox/addon/http-header-live/) Displays the HTTP header. Edit it and send it.  
- The HTML &lt;form&gt; Element [Reference](https://developer.mozilla.org/en-US/docs/Web/HTML/Element/form)
- [XMLHttpRequest](https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest)
- [Using XMLHttpRequest](https://developer.mozilla.org/en-US/docs/Web/API/XMLHttpRequest/Using_XMLHttpRequest)
- [Element.innerHTML](https://developer.mozilla.org/en-US/docs/Web/API/Element/innerHTML) gets or sets the HTML markup contained within the element.
- [CSP Cheat Sheet](https://cheatsheetseries.owasp.org/cheatsheets/Content_Security_Policy_Cheat_Sheet.html)
- [XSS Filter Evasion](https://cheatsheetseries.owasp.org/cheatsheets/XSS_Filter_Evasion_Cheat_Sheet.html)

### Examples
- [https://hackerone.com/reports/106293](https://hackerone.com/reports/106293/)
- [https://hackerone.com/reports/104359](https://hackerone.com/reports/104359/)
- [https://klikki.fi/yahoo-mail-stored-xss](https://klikki.fi/yahoo-mail-stored-xss/)
- [https://mahmoudsec.blogspot.com/2015/09/how-i-found-xss-vulnerability-in-google.html](https://mahmoudsec.blogspot.com/2015/09/how-i-found-xss-vulnerability-in-google.html)
- [http://strukt93.blogspot.com/2016/07/united-to-xss-united.html](http://strukt93.blogspot.com/2016/07/united-to-xss-united.html)

### Grading

Post your report in [Marmoset](https://cs.ycp.edu/marmoset) by the scheduled due date in the syllabus. Your grade for this lab will be composed of:
- 30% - Design
- 30% - Observations
- 40% - Explanation
- *Extra Credit* if you pursue further investigation, beyond what is required by the lab description.
