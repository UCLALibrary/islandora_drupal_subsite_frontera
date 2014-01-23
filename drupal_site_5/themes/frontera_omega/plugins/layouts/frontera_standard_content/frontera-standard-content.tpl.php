<div<?php print $css_id ? " id=\"$css_id\"" : ''; ?> class="container <?php print $classes; ?>">

  <?php if (!empty($content['image'])): ?>
  <div class="region-image">
    <?php print render($content['image']); ?>
  </div> <!-- /.region-image -->
  <?php endif; ?>

  <?php if (!empty($content['summary'])): ?>
  <div class="region-summary">
    <?php print render($content['summary']); ?>
  </div> <!-- /.region-summary -->
  <?php endif; ?>

  <?php if (!empty($content['details'])): ?>
  <div class="region-details">
    <?php print render($content['details']); ?>
  </div> <!-- /.region-details -->
  <?php endif; ?>

  <?php if (!empty($content['complementary'])): ?>
  <div class="region-complementary">
    <?php print render($content['complementary']); ?>
  </div> <!-- /.region-complementary -->
  <?php endif; ?>

</div> <!-- /.<?php print $classes; ?> -->
