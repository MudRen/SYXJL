
// Room: /jingzhou/huatai.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "��̨");
        set("long", @LONG
�����Ǿ��ݳǵ������ģ�һ���ܿ����Ĺ㳡��������ʯ���档�м���
���ܴ�Ļ�̳���ܱ龭������һЩ���ֺ��е��������������Ҳ��Щ
������������ݡ���̳���пô��������̸���ڣ��ݴ�����ǧ������䣬
���������е���ʷ��֤������Կ������������Ը��ص����ˣ������ȥ��
���Ĺ���ÿ�����ᶼ�����￪չ������һֱ���������У�һ�ɷ�����
�󣬶��治ʱ�ش�����������֣����ߵĽֵ��Ե������ñȽ�ïʢ������
��ܶ��˶��������������������Ȳ衣
LONG
        );
        set("outdoors", "jingzhou");
        set("exits", ([
                "east"  : __DIR__"jingzhonglu",
                "south" : __DIR__"nanmendajie",
                "west"  : __DIR__"xidajie3",
                "north" : __DIR__"sanyijie",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}