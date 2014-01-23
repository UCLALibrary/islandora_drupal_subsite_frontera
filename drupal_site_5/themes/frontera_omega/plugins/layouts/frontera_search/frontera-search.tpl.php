<div<?php print $css_id ? " id=\"$css_id\"" : ''; ?> class="container <?php print $classes; ?>">

  <?php if (!empty($content['top'])): ?>
  <div class="region-top">
    <?php print render($content['top']); ?>
  </div> <!-- /.region-top -->
  <?php endif; ?>

  <?php if (!empty($content['filters'])): ?>
  <div class="region-filters">
    <?php print render($content['filters']); ?>
  </div> <!-- /.region-summary -->
  <?php endif; ?>

  <?php if (!empty($content['results'])): ?>
  <div class="region-results">
    <?php print render($content['results']); ?>
  </div> <!-- /.region-results -->
  <?php endif; ?>

</div> <!-- /.<?php print $classes; ?> -->
