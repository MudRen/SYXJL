
// Room: /chang'an/yuqihang.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
����һ��ר�ž�Ӫ������ĵ��̣���ǽ�ϻ������š��׺����������ᣬ
������ů�����̡����ַ���Ҳ��֪���ǳ���˭���ֱʡ����ڳ����������
��ʢ�������񣬵���һ�εĿ���һ�㶼���ӵ�����������ȥ��
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