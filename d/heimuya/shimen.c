inherit ROOM;

void create()
{
        set("short", "ʯ��");
        set("long", @LONG
�õ�һ����ʯ��ǰ��ֻ�����Կ������д��֣������ǡ��ĳ���¡�����
���ǡ�����Ӣ����������Ͽ��š�һͳ�������ĸ�����֡�
LONG
        );
        set("no_clean_up", 0);
        set("exits", ([ /* sizeof() == 2 */
"westup" : __DIR__"ryping",
"eastdown" : __DIR__"shijie2",
]));
        set("objects", ([ /* sizeof() == 1 */
            __DIR__"npc/jia" : 1,
            __DIR__"npc/shashou2" : 2,
  ]));

        setup();
}

int valid_leave(object me, string dir)
{
        mapping myfam;
        myfam = (mapping)me->query("family");
        if(me->query_temp("hmy_enter") && dir == "westup")
        call_out("del_tmp",1000,me);
        else {

        if ((!myfam || myfam["family_name"] != "�������") && dir == "westup" &&
                objectp(present("jia bu", environment(me))))
           return notify_fail("�ֲ��ȵ���վס���㲻��������̵��ӣ��������ڡ�\n");
             }
                
        return ::valid_leave(me, dir);
}
void del_tmp(object me)
{
        if ( objectp(me) ) me->delete_temp("hmy_enter");
}
