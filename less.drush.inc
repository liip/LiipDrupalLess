<?php

function less_drush_cache_clear(&$types) {
  $types['less'] = 'less_flush_caches';
}
