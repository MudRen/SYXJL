
// Room: /huoshan/huajin3.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "����");
        set("long", @LONG
��������һ�����߿����ʻ���С���ϣ�·�ߵĻ��������涷����
����Ļ�����ܽг�������������е����ȵ�������Ļ�ȫ����
�����Ʒ����Щֻ���ڻʹ����߽�������ĸ�ۡ����ר�ŵĻ�����
�������Ļ���������ȱȽ��ǣ����ɵ���������Ұ�⣬�㲻֪Ӧ��
��Ϊ���е����һ�������ϧ��
LONG
        );
        set("outdoors", "lvzhou");
        set("exits", ([
                "south" : __DIR__"huajing4",
                "northdown" : __DIR__"huajing2",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}