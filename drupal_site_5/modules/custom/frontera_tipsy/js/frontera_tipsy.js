(function($) {
  Drupal.behaviors.tipsy = {
    attach: function(context, settings) {
      var selectors = '.frontera-tipsy-cut-text';
      $(selectors).each(function(){
        var title = function() {
          return $(this).children('.frontera-tipsy-long-text').html();
	    };

          $(this).tipsy({
          title: title,
          html: 1,
          delayIn: 0,
          delayOut: 0,
          fade: 1,
          gravity: 'w',
          offset: 0,
          opacity: 0.8,
          trigger: 'hover'
        });
      });
    }
  };
})(jQuery);
