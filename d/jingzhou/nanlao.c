
// Room: /jingzhou/nanlao.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
������˺ܶ࣬����Ե�ӵ����������û���˴�ɨ��ɧ����ζ��������
����ùζ�����˵Ľ�Ѿ�ӵ�����ı���˯����Ҳ�ѵ�Ų���ѣ������㿪ʼ��
�ڲ�ȥ��һ���ط��������˰ɣ��������������������֪�������͵����Ӻ�
��ȥ��
LONG
        );
//        set("outdoors", "jingzhou");
        set("exits", ([
                "west"  : __DIR__"jianyuguodao1",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}