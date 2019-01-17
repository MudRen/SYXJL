// Room: hantan.c



inherit ROOM;



void create()

{

        set("short", "碧水寒潭");

        set("long", @LONG

潭水冰冷刺骨，冷得你连打寒颤，牙齿“的的”的直响。你游到岸边，爬上

岸，躺在青草地上向四周细细观望：

    群山环绕之中有一潭碧波，清澈见底，一尾尾不知名的小鱼儿欢畅地游

来游去，好不悠闲自在。风吹潭面，荡起层层水波，在阳光的照耀下，闪出

粼粼波光。啊...！好一幅优美的风景画！...不！！！！

    比画更自然，更灵动，更舒畅！！！！！！！

LONG

        );

        set("exits", ([ /* sizeof() == 1 */

  "east" : __DIR__"hantan-hole1",

]));

        set("no_clean_up", 0);

        set("outdoors", "none");



        setup();

}

void init()

{

          add_action("do_jumpup", "jumpup");

}



int do_jumpup(string arg)

{

        object me;

        me = this_player();

        message_vision("$N两膝略曲，双足一点地，提气纵身，拔地而起！\n", me);

                message_vision("空中变换身形，一个空翻，轻飘飘地落在地上！\n", me);

    me->move("/d/mj/banshanyao");



        return 1;

}







