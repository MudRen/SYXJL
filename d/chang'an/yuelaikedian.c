
// Room: /chang'an/yuelaikedian.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�����͵�");
        set("long", @LONG
����һ�Ҷ�����������ʿ��˵���������Ŀ�ջ�����ǵ�������һ�㶼
ס���������Ҳ����һЩ�����ˣ����̰ͼ���޷�һ�Ǽ۸���ʣ���ס
�������������Щ�����ϵ���ഫ�š�
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "west"  : __DIR__"nandajie2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}