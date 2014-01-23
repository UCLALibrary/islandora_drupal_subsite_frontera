(function ($) {

Drupal.behaviors.ct_recordings_players = {
    attach: function() {
        var settings = Drupal.settings.ct_recordings;

        jwplayer.key="wjk3sc1OhHwhDELvP9KokJZxeKsG6//FrhqbMg==";

        for (var player_id in settings) {
            jwplayer(player_id).setup({
                sources: [{
                    file: settings[player_id].playlist_source
                },{
                    file: settings[player_id].mp3_source
                }],
                rtmp: { bufferlength: 3 },
                primary: settings[player_id].primary,
                height: settings[player_id].height,
                width: settings[player_id].width
            });
        }
    }
};

})(jQuery);
