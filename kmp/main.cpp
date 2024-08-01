#include <vector>
#include <string>

// i�������ˣ��ڵ�ǰֵ����¾����ܿ����ҵ���ƥ����ַ�����j������0��δƥ���������һ��ƥ�䣨ָ���Ǹı��������ƥ�䣩

std::vector<int> getNext(std::string needle)
{
	// ��ģʽ�����ı���ƥ���˼������ͬ�ģ���ģʽ���ڶ�ÿ���Ӵ�ƥ��ǰ׺�ͺ�׺�ص��ĳ���
	// ����i��ÿ���ִ���β��ָ�룬�������ˣ�jָ��ǰ׺�Ľ�β����next�������
	int M = needle.size();
	int j = 0;
	std::vector<int> next_pat(M);
	next_pat[j] = 0;
	for (int i = 1; i < M; i++)
	{
		while (needle[i] != needle[j])
		{
			// ����ǰǰ׺��β�ͺ�׺��β��һ�£����ݻ���j
			// ��ǰ�ַ�֮ǰ���Ѿ�ƥ�����ˣ�����next������˵��ص����ȿɼ����ظ��Ƚ�
			if (j > 0)
			{
				j = next_pat[j - 1];
			}
			else
			{
				j = 0;
				break;
			}
		}
		// ��ƥ��ɹ��ص�����Ϊ�����ż�1�������ص�����Ϊ0
		// ������������ԭ�����Ե�ǰΪ��β��j�Ѿ����˵�����λ�ã�ƥ�������¼�ص����ȣ�����Ϊû��ƥ��ɹ�
		if (needle[i] == needle[j])
		{
			j += 1;
			next_pat[i] = j;
		}
		else
		{
			next_pat[i] = 0;
		}
	}
	return next_pat;
}

int main()
{
	std::string needle = "aabaaac";
	std::string txt = "aabaaabaaac";
	int M = needle.size();
	int N = txt.size();
	int j = 0;
	std::vector<int> next_pat(M);  // ÿ��Ԫ�ص�ֵ��ʾ������ǰ�ַ����ִ�ǰ׺��׺��ص�����
	next_pat = getNext(needle);
	for (int i = 0; i < N; i++)
	{
		// �ı���ָ���������ˣ�ģʽ��ָ���ڵ�ǰ�ַ���ƥ��ʱ����next������ˣ�
		// ����ǰ�ַ�֮ǰ�ľ�ƥ�䣬��һ���ִ���ǰ��׺�ص���������j����λ�ôӶ������ظ��Ƚ�
		// ��ģʽ��ָ���Ѿ����˵�0�ˣ��������ѭ����˵���޷�ƥ���˽�����һ���ı����Ŀ���
		while (txt[i] != needle[j])
		{
			if (j > 0)
			{
				j = next_pat[j - 1];
			}
			else
			{
				j = 0;
				break;
			}
		}
		// ��ǰ�ַ�ƥ���Ϻ�ģʽ��ָ����ƣ����ŵ�ǰ��ƥ��׶�
		if (txt[i] == needle[j])
		{
			j += 1;
		}
		// ��ģʽ��ָ���Ѿ�������ģʽ����β��˵���Ѿ�ȫ��ƥ���ϣ��ɷ��ض�Ӧ���ı���ָ��
		if (j == M)
		{
			return i - M + 1;
		}
	}
	return 0;
}