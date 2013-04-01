LESS CSS Preprocessor

Files in lessphp/ are from the library at http://leafo.net/lessphp/

The LICENSE file in lessphp/ applies only to files within lessphp/


Requirements
Libraries API.
lessphp library unpacked so that 'lessc.inc.php' is located at 'sites/all/libraries/lessphp/lessc.inc.php'.


LESS Development:

Syntax:
http://leafo.net/lessphp/docs/

File placement:
If your source file was "sites/all/modules/test/test.css.less"
Then your compiled file will be "sites/[yoursite_or_default]/files/less/[random.string]/sites/all/modules/test/test.css"

Use:
The following two examples provide equivalent functionality.

drupal_add_css:

<?php
$module_path = drupal_get_path('module', 'less_demo');
drupal_add_css($module_path . '/styles/less_demo.css.less');
?>


.info file:

stylesheets[all][] = styles/less_demo.css.less


Compatibility:

Should work with most themes and caching mechanisms.

CSS Aggregation:
Fully compatible with "Optimize CSS files" setting on "Admin->Site configuration->Performance" (admin/settings/performance).

RTL Support:
RTL support will work as long as your file names end with ".css.less".

Assuming your file is named "somename.css.less", Drupal automatically looks for a file name "somename-rtl.css.less"