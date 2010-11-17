// $Id$

LESS CSS Preprocessor

Files in lessphp/ are from the library at http://leafo.net/lessphp/

The LICENSE file in lessphp/ applies only to files within lessphp/


DIRECTIONS:

Can be invoked by either

"drupal_add_css('filename.css.less')"

or in the .info file of your theme

"stylesheets[all][] = filename.css.less"



RTL:

As long as you name your files like

"filename.css.less"

Drupal should automatically detect and use 

"filename-rtl.css.less"

if the file is present.



INCLUDES:

Files can be included using the standard @import syntax.
Each file that is included in such a manner will inserted into the including document and then the including document will be parsed.