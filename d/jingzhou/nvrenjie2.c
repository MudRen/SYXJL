
// Room: /jingzhou/nvrenjie2.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "Ů�˽�");
        set("long", @LONG
��Ȼֻ��ר��Ů����Ʒ�ĵط����������̶Ⱦ������������ҵ���ٵ���
��ȥ������Ů�˻��������ߵ�������������һ��ר�����ߵĵ��̣��ϱ���һ
����֬���۵ꡣ
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"nvrenjie1",
                "south" : __DIR__"nvrenjiepu2",
                "west"  : __DIR__"nvrenjie3",
                "north" : __DIR__"nvrenjiepu3",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}