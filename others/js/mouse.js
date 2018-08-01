onload = function () {
    var a=1;
    if (navigator.userAgent.match(/(phone|pad|pod|iPhone|iPod|ios|iPad|Android|wOSBrowser|BrowserNG|WebOS)/i))return;
    function A__getColor() {
        var colorElements = "0,1,2,3,4,5,6,7,8,9,a,b,c,d,e,f";
        var colorArray = colorElements.split(",");
        var color = "#";
        for (var i = 0; i < 6; i++) {
            color += colorArray[Math.floor(Math.random() * 16)];
        }
        return color;
    }
    var $html = document.getElementsByTagName("html")[0];
    var $body = document.getElementsByTagName("body")[0];
    $html.onclick = function (e) {
        var $elem = document.createElement("b");
        $elem.style.color = A__getColor();
        $elem.style.zIndex = 9999;
        $elem.style.position = "absolute";
        $elem.style.select = "none";
        var x = e.pageX;
        var y = e.pageY;
        $elem.style.left = (x - 10) + "px";
        $elem.style.top = (y - 20) + "px";
        clearInterval(anim);
        var list = new Array("(･ω´･ )", "(っ・Д・)っ",
            "OωO", "(๑•́ ∀ •̀๑)", "(ﾟ∀。)", "(´・ω・`)", "(`・ω・´)",
            "(つд⊂)", "Σ(ﾟдﾟ)", "σ`∀´)σ", "-`д´-", "(๑•́ ₃ •̀๑)",
            "( º﹃º )", "( ˘･з･)", "(〃∀〃)", "(๑• . •๑)",
        );
        var le = list.length;
        $elem.innerText = list[Math.floor(Math.random() * le)]
        $elem.style.fontSize = Math.random() * 10 + 8 + "px";
        var increase = 0;
        var anim;
        setTimeout(function () {
            anim = setInterval(function () {
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