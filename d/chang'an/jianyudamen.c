// Room: /chang'an/jianyudamen.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "��������");
        set("long", @LONG
�����Ǹ�ǽɭɭ��������Խ�����ſ�վ�źü������ۺ�Ѳ����������
�����ؿ������ܵ��������û����ÿ���߿�����ñ�Ѳ��ץ��Ѳ������
��û�ꡣ
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