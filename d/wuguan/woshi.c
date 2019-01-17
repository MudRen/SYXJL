// Room: /d/wuguan/woshi.c
// Date: 99/05/30 by Byt

inherit ROOM;
void create()
{
        set("short", "卧室");
        set("long", @LONG
这里是武馆馆主的卧室，房子并不大，很整洁简朴，被子叠的整整
齐齐，帐子挂了起来，靠窗边摆了一盆盆景，一张小桌，放着几本书。
LONG );
        set("no_fight",1);
        set("no_steal",1);
        set("no_beg",1);
        set("outdoors", "wuguan");
        set("exits", ([
                "south" : __DIR__"changlang4",
        ]));
        setup();
        replace_program(ROOM);
}
