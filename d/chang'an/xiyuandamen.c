
// Room: /chang'an/xiyuandamen.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "ϷԺ����");
        set("long", @LONG
������ǳ������ڵ�ϷԺ�ˣ������������е�ʱ��ϲ���ܵ�������
��������Ũ�����±���ζ����ǻ����˵����ԭ�����������Ļ���С���ɸ�
��˽���ˡ�Ϊ������ϷԺһֱҲû�п��ţ�ϷԺ�ϰ����ڼ���Ҫ��������
�Ĵ������½ǡ�
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "north" : __DIR__"dongdajie1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}