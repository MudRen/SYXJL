
// Room: /chang'an/yizhan.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "��վ");
        set("long", @LONG
������ǳ������ڵĴ���վ�ˣ����ڴ˵ع��񷱶࣬���������Ŀ���
һ�첻֪���ж��٣�������ʹ�糾���͵����ӣ�ȷʵ��һ���ǳ��������
�顣�ٸ���ĵͼ���Ա������������ȡ����
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "north" : __DIR__"dongdajie3",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}