<div<?php print $css_id ? " id=\"$css_id\"" : ''; ?> class="container <?php print $classes; ?>">

  <?php if (!empty($content['first'])): ?>
  <div class="footer-column footer-column--first">
    <?php print render($content['first']); ?>
  </div>
  <?php endif; ?>

  <?php if (!empty($content['last'])): ?>
  <div class="footer-column footer-column--last">
    <?php print render($content['last']); ?>
  </div>
  <?php endif; ?>

</div>
