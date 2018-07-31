onload = function() {
    var click_cnt = 0;
    var $html = document.getElementsByTagName("html")[0];
    var $body = document.getElementsByTagName("body")[0];
    $html.onclick = function(e) {
        var $elem = document.createElement("b");
        $elem.style.color = "#AEEEEE";
        $elem.style.zIndex = 9999;
        $elem.style.position = "absolute";
        $elem.style.select = "none";
        var x = e.pageX;
        var y = e.pageY;
        $elem.style.left = (x - 10) + "px";
        $elem.style.top = (y - 20) + "px";
        clearInterval(anim);
        var list = new Array("(･ω´･ )","(っ・Д・)っ",
            "OωO", "(๑•́ ∀ •̀๑)", "(ﾟ∀。)", "(´・ω・`)","(`・ω・´)",
            "(つд⊂)", "Σ(ﾟдﾟ)", "σ`∀´)σ", "-`д´-","(๑•́ ₃ •̀๑)",
            "( º﹃º )", "( ˘･з･)", "(〃∀〃)","(๑• . •๑)",
        );
        var le=list.length;
        $elem.innerText = list[Math.floor(Math.random() * le)]
        $elem.style.fontSize = Math.random() * 10 + 8 + "px";
        var increase = 0;
        var anim;
        setTimeout(function() {
        	anim = setInterval(function() {
	            if (++increase == 150) {
	                clearInterval(anim);
			$body.removeChild($elem);
	            }
	            $elem.style.top = y - 20 - increase + "px";
	            $elem.style.opacity = (150 - increase) / 120;
	        }, 8);
        }, 70);
        $body.appendChild($elem);
    };
};