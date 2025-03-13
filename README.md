# Hospital Management System Project

## 1. Branch Management Rules

| Branch Type  | Purpose                         | Naming Convention                   |
|-------------|---------------------------------|-----------------------------------|
| main        | Stable version, no direct push  | Protected branch                  |
| dev         | Integration development branch  | Long-term existence               |
| feature/*   | New feature development         | feature/patient-admission        |
| bugfix/*    | Bug fixes                       | bugfix/transfer-bug              |

---

## 2. Daily Development Process

### 2.1 Synchronize the Latest Code
```bash
git checkout dev
git pull origin dev
```

### 2.2 Create a Feature Branch
```bash
git checkout -b feature/patient-admission  # Patient admission feature
```

### 2.3 Development and Commit
After modifying the code, commit in small steps:
```bash
git add src/patient.cpp
git commit -m "feat: Implement patient admission registration (linked to pharmacy bill)"
```

### 2.4 Push Branch to Remote
```bash
git push -u origin feature/patient-admission
```

### 2.5 Create a Pull Request (PR)
Create a PR on GitHub to merge `feature/patient-admission` into `dev`.
The PR must include:
- Feature description
- Test result screenshots (posted in the WeChat group)

### 2.6 Merge and Cleanup
After PR approval, merge into `dev` and delete the merged feature branch:
```bash
git branch -d feature/patient-admission
git push origin --delete feature/patient-admission
```

---

## 3. Common Issues and Solutions

### 3.1 Handling Merge Conflicts
Example: Multiple developers modified the same area in `HospitalBranch.cpp`.

Solution steps:
```bash
git fetch origin
git rebase origin/dev   # Rebase on the feature branch
```
Resolve conflicts manually, then:
```bash
git add .
git rebase --continue
git push -f  # Force push the updated branch
```

---

## 4. Regular Synchronization

### 4.1 Start Work Every Day
```bash
git checkout dev
git pull --rebase
```

### 4.2 Merge `dev` into `main` Weekly
```bash
git checkout main
git merge --no-ff dev  # Non-fast-forward merge
git push origin main
```

---

## 5. Git Command Quick Reference

| Scenario             | Command                                    |
|----------------------|------------------------------------------|
| Discard local changes | `git checkout -- <file>`                |
| Reset to a commit    | `git reset --hard <commit-hash>`        |
| View branch history  | `git log --graph --oneline --all`       |
| Stash current changes| `git stash`                              |
| Compare two branches | `git diff dev..feature/patient`         |
| Force sync remote branch | `git fetch --all && git reset --hard origin/dev` |

---

## 6. 中文版 README

### 1. 分支管理规范

| 分支类型   | 用途                          | 命名规范                          |
|------------|-----------------------------|--------------------------------|
| main       | 稳定版，禁止直接推送         | 受保护分支                      |
| dev        | 集成开发分支                 | 长期存在                        |
| feature/*  | 新功能开发（如患者管理模块） | feature/patient-admission     |
| bugfix/*   | 修复问题                      | bugfix/transfer-bug           |

---

### 2. 日常开发流程

#### 2.1 同步最新代码
```bash
git checkout dev
git pull origin dev
```

#### 2.2 创建特性分支
```bash
git checkout -b feature/patient-admission  # 患者入院功能
```

#### 2.3 开发与提交
修改代码后，进行小步提交：
```bash
git add src/patient.cpp
git commit -m "feat: 实现患者入院登记功能（关联药房账单）"
```

#### 2.4 推送分支到远程
```bash
git push -u origin feature/patient-admission
```

#### 2.5 发起 Pull Request (PR)
在 GitHub 页面发起 PR，将 `feature/patient-admission` 合并到 `dev`，
PR 必须包含：
- 功能描述
- 测试结果截图（发微信群里）

#### 2.6 合并与清理
PR 通过审查后，合并到 `dev`，然后删除已合并的特性分支：
```bash
git branch -d feature/patient-admission
git push origin --delete feature/patient-admission
```

---

### 3. 常见问题与解决方案

#### 3.1 处理合并冲突
示例：多人修改了 `HospitalBranch.cpp` 的同一区域。

解决步骤：
```bash
git fetch origin
git rebase origin/dev   # 在特性分支上变基
```
手动解决冲突后：
```bash
git add .
git rebase --continue
git push -f  # 强制推送更新分支
```

---

### 4. 定期同步

#### 4.1 每天开始工作前
```bash
git checkout dev
git pull --rebase
```

#### 4.2 每周合并 `dev` 到 `main`
```bash
git checkout main
git merge --no-ff dev  # 非快进合并
git push origin main
```

---

### 5. Git 常用命令速查

| 场景                 | 命令                                     |
|----------------------|--------------------------------------|
| 撤销本地修改        | `git checkout -- <file>`             |
| 重置到某个提交      | `git reset --hard <commit-hash>`    |
| 查看分支关系        | `git log --graph --oneline --all`   |
| 暂存当前修改        | `git stash`                          |
| 比较两个分支差异    | `git diff dev..feature/patient`     |
| 强制同步远程分支    | `git fetch --all && git reset --hard origin/dev` |

### 6. 多文件编译
示例：跨文件夹多文件编译 <Doctor>
1. 在Doctor文件夹内创建CMakeLists.txt文件
```bash
cmake_minimum_required(VERSION 3.10)

# 定义项目名称
project(DoctorTest)

# 设置 C++ 标准
set(CMAKE_CXX_STANDARD 20)
set(CMAKE_BUILD_TYPE Debug)

add_compile_options(-g)

include_directories(
    header
    C:/Users/26773/OneDrive/codefile/3400FinalProj/test/MedicalStaff/header
)

add_executable(DoctorTest
    C:/Users/26773/OneDrive/codefile/3400FinalProj/test/MedicalStaff/MedicalStaff.cpp
    C:/Users/26773/OneDrive/codefile/3400FinalProj/test/Doctor/Doctor.cpp
    C:/Users/26773/OneDrive/codefile/3400FinalProj/test/Doctor/DoctorTest.cpp
)
```
2. 生成build文件夹
```bash
# 新建文件夹build
mkdir build
# 进入文件夹
cd build
# 生成Makefile
cmake -G "MinGW Makefiles" ..
# 编译代码
mingw32-make
```
=======
