export const template = `
  <?xml version= "1.0" encoding= "UTF-8"?>
  <document>
    <print-mode mode= {{printMode}} />
    {{#printRows}}
     {{#feedLine}}
     <line-feed />
     {{/feedLine}}
     {{^feedLine}}
     {{#isBold}}
     <bold>
      <align mode= {{alignment}}>
        <text-line size= '{{size}}'>{{text}}</text-line>
      </align>
     </bold>
     {{/isBold}}
     {{^isBold}}
      <align mode= {{alignment}}>
        <text-line size='{{size}}'>{{text}}</text-line>
      </align>
     {{/isBold}}
     {{/feedLine}}
    {{/printRows}}
    <paper-cut />
  </document>
`;
