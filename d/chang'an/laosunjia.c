
// Room: /chang'an/laosunjia.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "Сʳ��");
        set("long", @LONG
����һ�Һ�С��С�Ե꣬������Ҳ��ɾ������ﵽ�����������ζ����
ǽ�ǵ����Ӿ�Ȼ����һ��СС���Ҷ��Լ���ܱ�������д�š���һ�롱��
�����˻ҳ�����˵������ϰ�����Ǵ���Զ���±����ġ�
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "north" : __DIR__"nanyuanmen",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}