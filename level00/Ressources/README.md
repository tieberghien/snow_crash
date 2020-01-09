### CTF

First, go to the Feedback page. You are asked to leave a feedback in the guestbook. The Message field is vulnerable to XSS filter bypass. The correct syntax for this exploit is something along those lines:
```javascript
    <script>alert('test');</script>
```
### How to protect yourself

There are multiple solutions:
1. [HTML/XML escape](https://www.w3.org/International/questions/qa-escapes#use) all user inputs so they can't be interpreted by the browser as HTML.
2. [Javascript escape](https://github.com/OWASP/CheatSheetSeries/blob/master/cheatsheets/DOM_based_XSS_Prevention_Cheat_Sheet.md#safe-and-functionally-correct-example) all user inputs so they can never be interpreted as javascript.
3. Be more careful when inserting untrusted data in event handlers.
