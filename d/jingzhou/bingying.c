
// Room: /jingzhou/bingying.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "��Ӫ");
        set("long", @LONG
�����Ǳ�Ӫ���������鵽�����Ǿ�ʿ�������佫��ָ�����жӲ�����
�еĶ�������������ǽ��������˧��������ɫ��Ѱ�������ܡ�
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "south" : __DIR__"bingyingdamen",
         ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}