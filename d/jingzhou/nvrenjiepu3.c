
// Room: /jingzhou/nvrenjiepu3.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "Ů�˽ֵ���");
        set("long", @LONG
����һ��ר�������ߺɰ���С�꣬�������Ÿ������Ͱ�֮���������ţ�
����������һ��һ��ؽ��������ﴩ��ϥ���Ϸ���һ��û��������廨�ɰ���
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "south" : __DIR__"nvrenjie2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}