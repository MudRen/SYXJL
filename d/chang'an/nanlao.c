// Room: /chang'an/nanlao.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "�м�");
        set("long", @LONG
������˺ܶ࣬����Ե�ӵ����������û���˴�ɨ��ɧ����ζ������
�ǹ���ùζ�����˵Ľ�Ѿ�ӵ�����ı���˯����Ҳ�ѵ�Ų���ѣ������㿪
ʼ��ڲ�ȥ��һ���ط��������˰ɣ��������������������֪�������͵�
���Ӻó�ȥ��
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "north" : __DIR__"jianyuguodao",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}