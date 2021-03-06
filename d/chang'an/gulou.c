// Room: /chang'an/gulou.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "鼓楼");
        set("long", @LONG
这里就是城内的第最高建筑物鼓楼了。基座为青砖砌成，高八米，东
西长约五十二米，南北深三十八米；门洞高、宽均六米，处于南大街中央。
楼体建筑为砖墙木质重檐歇山式，琉璃瓦复项，重檐三滴水。第一层楼上
置腰檐和平座。西安鼓楼十分坚固，几百年来经过多次地震没有裂缝或变
形。多年来，每天有许多车马从楼洞驰过，也未受影响。
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"nanyuanmen",
                "south" : __DIR__"nandajie1",
                "west"  : __DIR__"changjie",
                "north" : __DIR__"nandajie2",
                "up"    : __DIR__"gulouerceng",                             
        ]));
        setup();
}
