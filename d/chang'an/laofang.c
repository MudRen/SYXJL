// Room: /chang'an/laofang.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�η�");
        set("long", @LONG
�����Ѻ��һ����һЩ����С�������������˷绯��������ˣ�����
Ҳ���������Եع���һ��ʱ�䣬��ʾС�ʹ�䡣��ǽ�Ϲ���һЩ�����
ǽ������ŤŤ��д�š����ܡ����֡�
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "south" : __DIR__"xunbufang",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}