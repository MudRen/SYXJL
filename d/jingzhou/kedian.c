
// Room: /jingzhou/kedian.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�͵�");
        set("long", @LONG
����һ�����۵�С��ջ�����ھ�������Ҫ�Ľ�ͨ��Ŧ����������ǳ�
��¡������οͶ�ѡ��������š���С����������æ������ת���Ӵ��Ų�
����ǻ�����Ľ������ͺ������ˡ��ſ�����һ����һ������(paizi)��
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"sanyijie2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}