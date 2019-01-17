
// Room: /chang'an/zhonglouerceng.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "钟楼二层");
        set("long", @LONG
你正站在钟楼二楼。钟楼分两层，三重檐，四角攒顶；深广各五间，
环以回廊，凭栏四望，可饱览古城全貌。南面悬挂着一口大铁钟，每日里
撞钟为人报时。单就从建筑规模而言，此楼居全国钟楼之冠。
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([                
                "down"  : __DIR__"zhonglou",                             
        ]));

        set("no_clean_up", 0);
        setup();
        "/clone/board/ca_b"->foo();
}
