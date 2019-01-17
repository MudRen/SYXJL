// oooc: 1998/08/5 



inherit ROOM;



void create()

{

        set("short", "冰山");

        set("long", @LONG

大冰山在日光的照射下发出刺眼的光芒，显得十分奇丽，这里到处都是

冰雪，冰山颇大，如陆地上之山丘，一眼望去，横百余丈，纵长几十丈，冰

山上滑不留步，这时你看见前面一小浮冰正在向北飘流。你的船就在上面不

远之处，周围结满了冰。

LONG

        );



        set("exits", ([

                "east" : __DIR__"bingshan",

                "south" : __DIR__"bingshan3",

                "north" : __DIR__"bingshan3",

                "west" : __DIR__"bingshan",

        ]));





        setup();

        replace_program(ROOM);

}

