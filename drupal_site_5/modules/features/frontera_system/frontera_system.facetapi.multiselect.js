Drupal.behaviors.frontera_systemFacetApiMultiselectWidget = {
  attach: function (context, settings) {
    // Go through each facet API multiselect element that is being displayed.
    jQuery('.facetapi-multiselect', context).each(function () {
      // Attach the behavior to it.

      console.log('Il codice del behaviors viene eseguito');

      //jQuery(this).addClass('chzn-select');
      //jQuery(this).chosen({max_selected_options: 5});

      // jQuery(this).multiselect({
      //   // Pass in whatever array of options you need here.
      // });
      
    });
  }
};