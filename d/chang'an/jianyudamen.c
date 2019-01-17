// Room: /chang'an/jianyudamen.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "监狱大门");
        set("long", @LONG
这里是高墙森森，难以逾越。大门口站着好几名衙役和巡捕，正虎视
耽耽地看着四周的情况。你没事最好快点走开，免得被巡捕抓到巡捕房问
个没完。
LONG
        );
        set("outdoors", "chang'an");
        set("exits", ([
                "east"  : __DIR__"jianyuguodao",
                "west"  : __DIR__"shangdelu2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}