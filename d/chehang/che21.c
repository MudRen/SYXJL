inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
����ɸɾ�����������������Ĵ����ӡ�������������������ӷ�϶��͸
��������֪�������ߵ������ˡ��������һ�����壬���������š���������ǰ
�棬һ·������һ·����غ���ʲôС��
LONG
        );

        setup();
}
void run(object ob)
{
        if (environment(ob) == this_object())
        ob->move(__DIR__"che22", 1);
        write("\n����������ޡ�ž����˦��һ�£��󳵺�¡¡�ؿ�������������\n\n");
}

void init()
{
       object ob = this_player();

    call_out("run", 3, ob);
}
