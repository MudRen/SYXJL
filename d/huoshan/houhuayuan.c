
// Room: /huoshan/houhuayuan.c
// SANZI 99/05/30

inherit ROOM;
void create()
{
        set("short", "��԰");
        set("long", @LONG
��Ȼ������ɳĮ�����ģ���������Ͽ�����ܳ�����Щ�ʻ��Ѿ�
��������е�����ˣ����޵Ļ��侺�࿪�ţ������������������
һЩɫ�ʰ�쵵ĺ��������Լ�϶�еĲ�ƺ����һЩ��ұ��Ů�ˣ���
��������˿���㲻�ɵ���ͷһ����
LONG
        );
        set("outdoors", "lvzhou");
        set("exits", ([
                "southeast" : __DIR__"xiaojing1",
                "north" : __DIR__"zoulang4",
        ]));

        set("no_clean_up", 0);
        setup();
        replace_program(ROOM);
}