
// Room: /jingzhou/xiaochidian.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "С�Ե�");
        set("long", @LONG
��������̵��ϰ�ʮ�־����������￪��һ��ר��СʳƷ�����棬ȷʵ
�����˺ܶ����⣬������Щ��ʵ��ϲ�������Ź�ֵ����˶���ڶ���������
Ϣ��Ů����Ҳϲ�������˾��ܵ�����ȵ�����ϲ�������ϡ�
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "north" : __DIR__"nvrenjie3",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}