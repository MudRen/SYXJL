
// Room: /jingzhou/wanjiadayuan.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "��Ҵ�Ժ");
        set("long", @LONG
���߽���Ժ��ӭ����һ����ɽˮ�أ����ϰ���һ�����ι�״��ʯͷ��
��˵�ǵ��껨ʯ�ٵ���ʯ��ˮ�ص����������˻��ݡ�������һ�û�������
���дУ��ڸ��˴���Ժ�ӡ�һ�������ߵ�ͨ����Ժ��
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"wanjiadazhai",
                "west"  : __DIR__"wanjiahouyuan",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}