
// Room: /chang'an/caizhudayuan.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "������Ժ");
        set("long", @LONG
���߽���Ժ��ӭ����һ����ɽˮ�أ����ϰ���һ�����ι�״��ʯͷ��
��˵�ǵ��껨ʯ�ٵ���ʯ��ˮ�ص����������˻��ݡ�������һ�û�������
���дУ��ڸ��˴���Ժ�ӣ��Ե���ɭ�ֲ���һ�������ߵ�ͨ����Ժ����
�����Ҷ����ء�
LONG
        );
//        set("outdoors", "chang'an");
        set("exits", ([
                "west"  : __DIR__"caizhuhouyuan",
                "east"  : __DIR__"caizhudamen"
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}