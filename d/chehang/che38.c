inherit ROOM;
void create()
{
        set("short", "������");
        set("long", @LONG
�����������Ȼ��֪������龰�����λ����ƣ�ͣͣ���ߣ���֪���˶����졭��
LONG
        );

        setup();
}
void run(object ob)
{
        ob = this_player();
        if (environment(ob) == this_object())
	message_vision("\n��ƥ������һ�˴����˹���������һ��ߺ�ȣ���ͣ��������\n",ob);        
	message_vision("\n�������˵�����������������佻����ɡ����漴�ƿ����š�\n",ob);   
	message_vision("\n$N�ӳ�������������\n",ob);	   		
        ob->move("/d/huanhua/zhenmei", 1);
}

void init()
{
       object ob = this_player();

    call_out("run", 10, ob);
}
