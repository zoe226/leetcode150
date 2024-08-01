#include <vector>
#include <string>

// i永不回退，在当前值情况下尽可能快速找到可匹配的字符，若j回退至0还未匹配则进入下一次匹配（指的是改变起点重新匹配）

std::vector<int> getNext(std::string needle)
{
	// 与模式串和文本串匹配的思想是相同的，在模式串内对每个子串匹配前缀和后缀重叠的长度
	// 其中i是每个字串结尾的指针，永不回退，j指向前缀的结尾根据next数组回退
	int M = needle.size();
	int j = 0;
	std::vector<int> next_pat(M);
	next_pat[j] = 0;
	for (int i = 1; i < M; i++)
	{
		while (needle[i] != needle[j])
		{
			// 若当前前缀结尾和后缀结尾不一致，根据回退j
			// 当前字符之前的已经匹配上了，根据next数组回退到重叠长度可减少重复比较
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
		// 若匹配成功重叠长度为索引号加1，否则重叠长度为0
		// 可以这样做的原因是以当前为结尾，j已经回退到极限位置，匹配上则记录重叠长度，否则为没有匹配成功
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
	std::vector<int> next_pat(M);  // 每个元素的值表示包含当前字符的字串前缀后缀最长重叠个数
	next_pat = getNext(needle);
	for (int i = 0; i < N; i++)
	{
		// 文本串指针永不回退，模式串指针在当前字符不匹配时根据next数组回退，
		// 即当前字符之前的均匹配，这一段字串的前后缀重叠个数决定j回退位置从而避免重复比较
		// 若模式串指针已经回退到0了，结束这个循环，说明无法匹配了进入下一个文本串的开端
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
		// 当前字符匹配上后，模式串指针后移，接着当前的匹配阶段
		if (txt[i] == needle[j])
		{
			j += 1;
		}
		// 若模式串指针已经到达了模式串结尾，说明已经全部匹配上，可返回对应的文本串指针
		if (j == M)
		{
			return i - M + 1;
		}
	}
	return 0;
}