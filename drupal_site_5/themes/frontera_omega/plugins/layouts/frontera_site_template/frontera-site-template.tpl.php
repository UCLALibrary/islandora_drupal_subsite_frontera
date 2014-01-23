<div<?php print $css_id ? " id=\"$css_id\"" : ''; ?> class="l-page <?php print $classes; ?>">

  <div class="l-header">
    <aside class="l-region l-utility">
      <?php print render($content['utility']); ?>
    </aside>

    <div class="l-region l-branding">
      <?php print render($content['branding']); ?>
    </div>

    <nav class="l-region l-navigation">
      <?php print render($content['navigation']); ?>
    </nav>
  </div>

  <div class="l-main">
    <?php if (!empty($content['help'])): ?>
      <div class="l-region l-help">
        <?php print render($content['help']); ?>
      </div>
    <?php endif; ?>

    <div class="l-region l-content">
      <?php print render($content['content']); ?>
    </div>
  </div>

  <div class="l-footer" role="contentinfo">
    <?php print render($content['footer']); ?>
  </div>
</div>
