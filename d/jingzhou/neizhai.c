
// Room: /jingzhou/neizhai.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "��լ");
        set("long", @LONG
���������ŵ���լ��ס����֪���ļҾ졣���˵��˾͸�ֹ���ˡ���ǰ
����һ�����µ�С��¥��
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "south" : __DIR__"yamendatang",
         ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}