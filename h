local Library = loadstring(game:GetObjects("rbxassetid://7657867786")[1].Source)("Pepsi's UI Library")

-- Create main window
local Window = Library:CreateWindow({
    Name = 'Yero.Hub | ❗South Bronx❗',
    Themeable = {
        Info = 'By Ace💫',
        Credit = True, -- Shows library credits
    },
    DefaultTheme = shared.themename or '{"__Designer.Colors.main":"FF0000"}'
})
-- Create tab and section
local GeneralTab = Window:CreateTab({Name = 'Main'})

local MainSection = GeneralTab:CreateSection({
    Name = 'Server Settings',
    Side = 'Left'
})

MainSection:AddButton({
    Name = 'Bypass AntiCheat',
    Callback = function()
        for i = 1, 2 do
            loadstring(game:HttpGet("https://pastefy.app/CZejhom2/raw"))()
--[[    local nums = {1, 2, 3, 4, 5, 6, 7, 8, 9, 0}
    local remote1;
    local remote1args
    local remote2;
    local remote2args
    local remote3;
    local remote3args
    local remote4;
    local remote4args
    local index = 0
    
    for i, v in pairs(game.ReplicatedStorage:GetChildren()) do
        for z, x in pairs(nums) do
            if string.match(v.Name, tostring(x)) then
                index += 1
                if index == 1 then
                    remote1 = v:FindFirstChildOfClass("RemoteFunction")
                elseif index == 2 then
                    remote2 = v:FindFirstChildOfClass("RemoteFunction")
                elseif index == 3 then
                    remote3 = v:FindFirstChildOfClass("RemoteFunction")
                elseif index == 4 then
                    remote4 = v:FindFirstChildOfClass("RemoteFunction")
                end
            end
        end
    end
    function deepclone(table)
        local tbl = {}
        for i, v in pairs(table) do
            if typeof(v) == "table" then
                table.insert(tbl, deepclone(v))
            else
                table.insert(tbl, v)
            end
        end
        return tbl
    end
    hookfunction(remote1.InvokeServer, function(args)
        print("Found Remote1")
        if not remote1args then
            if typeof(args) == "table" then
                remote1args = deepclone(args)
            else
                remote1args = args
            end
        end
    end)
    hookfunction(remote2.InvokeServer, function(args)
        if not remote2args then
            print("Found Remote2")
            if typeof(args) == "table" then
                remote2args = deepclone(args)
            else
                remote2args = args
            end
        end
    end)
    hookfunction(remote3.InvokeServer, function(args)
        if not remote3args then
            print("Found Remote3")
            if typeof(args) == "table" then
                remote3args = deepclone(args)
            else
                remote3args = args
            end
        end
    end)
    hookfunction(remote4.InvokeServer, function(args)
        if not remote4args then
            print("Found Remote4")
            if typeof(args) == "table" then
                remote4args = deepclone(args)
            else
                remote4args = args
            end
        end
    end)
    
    task.spawn(function()
        repeat task.wait() until remote1args
        while task.wait(1) do
            remote1:InvokeServer(remote1args)
        end
    end)
    task.spawn(function()
        repeat task.wait() until remote2args
        while task.wait(1) do
            remote2:InvokeServer(remote2args)
        end
    end)
    task.spawn(function()
        repeat task.wait() until remote3args
        while task.wait(1) do
            remote3:InvokeServer(remote3args)
        end
    end)
    task.spawn(function()
        repeat task.wait() until remote2args
        while task.wait(1) do
            remote4:InvokeServer(remote2args)
        end
    end)
    getgenv().dsaofihndsavousdnvoiusd = Instance.new("ScreenGui", game.Players.LocalPlayer.PlayerGui)
    repeat task.wait() until remote1args or remote2args or remote3args or remote4args
    for _,v in next, getgc(true) do
        if type(v) == "function" then
          name = tostring(getinfo(v).name)
          if name == "delay" then
                local Old;Old = hookfunction(v, function(...)
                Args = {...}
                if type(Args[2]) ~= "function" then
                    Args[2] = function()
                        return game:WaitForChild(math.random(1000000, 9e9))
                    end
                end
                return Old(...)
                end)
        end
            if name == "find" or name == "string.find" then
                local new;new = hookfunction(v,function(...)
                    if string.match(tostring(getcallingscript()),"?") then
                        return game:WaitForChild(math.random(1000000, 9e9))
                    end
                    return new(...)
                end)
            end
        end
      end
]]--
        end
    end
})


MainSection:AddButton({
    Name = 'Server Hop',
    Callback = function()
       local PlaceID = game.PlaceId
local AllIDs = {}
local foundAnything = ""
local actualHour = os.date("!*t").hour
local Deleted = false
local File = pcall(function()
    AllIDs = game:GetService('HttpService'):JSONDecode(readfile("NotSameServers.json"))
end)
if not File then
    table.insert(AllIDs, actualHour)
    writefile("NotSameServers.json", game:GetService('HttpService'):JSONEncode(AllIDs))
end

function TPReturner()
    local Site
    if foundAnything == "" then
        Site = game.HttpService:JSONDecode(game:HttpGet('https://games.roblox.com/v1/games/' .. PlaceID .. '/servers/Public?sortOrder=Asc&limit=100'))
    else
        Site = game.HttpService:JSONDecode(game:HttpGet('https://games.roblox.com/v1/games/' .. PlaceID .. '/servers/Public?sortOrder=Asc&limit=100&cursor=' .. foundAnything))
    end
    local ID = ""
    if Site.nextPageCursor and Site.nextPageCursor ~= "null" and Site.nextPageCursor ~= nil then
        foundAnything = Site.nextPageCursor
    end
    local num = 0
    for i,v in pairs(Site.data) do
        local Possible = true
        ID = tostring(v.id)
        if tonumber(v.maxPlayers) > tonumber(v.playing) then
            for _,Existing in pairs(AllIDs) do
                if num ~= 0 then
                    if ID == tostring(Existing) then
                        Possible = false
                    end
                else
                    if tonumber(actualHour) ~= tonumber(Existing) then
                        local delFile = pcall(function()
                            delfile("NotSameServers.json")
                            AllIDs = {}
                            table.insert(AllIDs, actualHour)
                        end)
                    end
                end
                num = num + 1
            end
            if Possible == true then
                table.insert(AllIDs, ID)
                wait()
                pcall(function()
                    writefile("NotSameServers.json", game:GetService('HttpService'):JSONEncode(AllIDs))
                    wait()
                    game:GetService("TeleportService"):TeleportToPlaceInstance(PlaceID, ID, game.Players.LocalPlayer)
                end)
                wait(4)
            end
        end
    end
end

function Teleport()
    while wait() do
        pcall(function()
            TPReturner()
            if foundAnything ~= "" then
                TPReturner()
            end
        end)
    end
end

Teleport()
    end
})

MainSection:AddButton({
    Name = 'Enable Reset Button',
    Callback = function()
         while true do
     game:GetService("StarterGui"):SetCore("ResetButtonCallback", true)
     game:GetService("RunService").RenderStepped:Wait()
end
    end
})

MainSection:AddButton({
    Name = 'Rejoin Server',
    Callback = function()
 local ts = game:GetService("TeleportService")
        local p = game:GetService("Players").LocalPlayer
        ts:Teleport(game.PlaceId, p) 
    end
})

MainSection:AddButton({
    Name = 'Anti AFK',
    Callback = function()
 local Players = game:GetService('Players')
        local VirtualUser = game:GetService('VirtualUser')
        local StarterGui = game:GetService('StarterGui')
        
        local player = Players.LocalPlayer
        
        player.Idled:connect(function()
            
            VirtualUser:CaptureController()
            VirtualUser:ClickButton2(Vector2.new())
        end)
    end
})

MainSection:AddButton({
    Name = 'Join Lowest Server',
    Callback = function()
 local Http = game:GetService("HttpService")
        local TPS = game:GetService("TeleportService")
        local Api = "https://games.roblox.com/v1/games/"
        
        local _place = game.PlaceId
        local _servers = Api.._place.."/servers/Public?sortOrder=Asc&limit=100"
        function ListServers(cursor)
            local Raw = game:HttpGet(_servers .. ((cursor and "&cursor="..cursor) or ""))
            return Http:JSONDecode(Raw)
        end
        
        local Server, Next; repeat
            local Servers = ListServers(Next)
            Server = Servers.data[1]
            Next = Servers.nextPageCursor
        until Server
        
        TPS:TeleportToPlaceInstance(_place,Server.id,game.Players.LocalPlayer)
    end
})

MainSection:AddButton({
    Name = 'Delete (J)',
    Callback = function()
     loadstring(game:HttpGet('https://[Log in to view URL]'))()
    end
})

local GeneralTab = Window:CreateTab({Name = 'Visuals'})
local MainSection = GeneralTab:CreateSection({
    Name = 'Visuals',
    Side = 'Left'
})

MainSection:AddToggle({
    Name = 'Name',
    Value = false,          -- Default state
    Flag = 'feature_toggle', -- Unique identifier
    Locked = false,         -- Prevent user changes
    Callback = function(state)
        loadstring(game:HttpGet('https://pastebin.com/raw/SDSsfiVN'))()
    end
})

MainSection:AddToggle({
    Name = 'Show Guns',
    Value = false,          -- Default state
    Flag = 'feature_toggle', -- Unique identifier
    Locked = false,         -- Prevent user changes
    Callback = function(state)
        loadstring(game:HttpGet("https://raw.githubusercontent.com/SergiuPro211/SouthCottonFREE/main/ShowGuns"))()
    end
})

MainSection:AddToggle({
    Name = 'Health',
    Value = false,          -- Default state
    Flag = 'feature_toggle', -- Unique identifier
    Locked = false,         -- Prevent user changes
    Callback = function(state)
        loadstring(game:HttpGet('https://pastebin.com/raw/mxLC8P1L'))()
    end
})

MainSection:AddToggle({
    Name = 'Distance',
    Value = false,          -- Default state
    Flag = 'feature_toggle', -- Unique identifier
    Locked = false,         -- Prevent user changes
    Callback = function(state)
        loadstring(game:HttpGet('https://pastebin.com/raw/nDnBxSyZ'))()
    end
})

MainSection:AddToggle({
    Name = 'Skeleton',
    Value = false,          -- Default state
    Flag = 'feature_toggle', -- Unique identifier
    Locked = false,         -- Prevent user changes
    Callback = function(state)
        loadstring(game:HttpGet("https://raw.githubusercontent.com/melvin123gp/shit/refs/heads/main/skeleto"))()()
    end
})

MainSection:AddToggle({
    Name = 'Cham',
    Value = false,          -- Default state
    Flag = 'feature_toggle', -- Unique identifier
    Locked = false,         -- Prevent user changes
    Callback = function(state)
        loadstring(game:HttpGet("https://raw.githubusercontent.com/melvin123gp/e21/refs/heads/main/111"))()()
    end
})

local GeneralTab = Window:CreateTab({Name = 'Player'})


local MainSection = GeneralTab:CreateSection({
    Name = 'Atm',
    Side = 'Right'
})

MainSection:AddToggle({
    Name = 'ATM Status',
    Value = false,          -- Default state
    Flag = 'feature_toggle', -- Unique identifier
    Locked = false,         -- Prevent user changes
    Callback = function(state)
        local player = game.Players.LocalPlayer
        local screenGui = player:FindFirstChild("PlayerGui"):FindFirstChild("ATMStatusGUI")

        if state then
            if not screenGui then
                screenGui = Instance.new("ScreenGui")
                screenGui.Name = "ATMStatusGUI"
                screenGui.Parent = player:WaitForChild("PlayerGui")

                local frame = Instance.new("Frame")
                frame.Size = UDim2.new(0, 300, 0, 400)
                frame.Position = UDim2.new(1, -320, 0.5, -200)
                frame.BackgroundColor3 = Color3.fromRGB(20, 20, 20)
                frame.BackgroundTransparency = 0.2
                frame.BorderSizePixel = 0
                frame.Parent = screenGui

                local corner = Instance.new("UICorner")
                corner.CornerRadius = UDim.new(0, 10)
                corner.Parent = frame

                local shadow = Instance.new("ImageLabel")
                shadow.AnchorPoint = Vector2.new(0.5, 0.5)
                shadow.Position = UDim2.new(0.5, 0, 0.5, 5)
                shadow.Size = UDim2.new(1, 40, 1, 40)
                shadow.BackgroundTransparency = 1
                shadow.Image = "rbxassetid://1316045217"  
                shadow.ImageTransparency = 0.7
                shadow.ZIndex = -1
                shadow.Parent = frame

                local title = Instance.new("TextLabel")
                title.Size = UDim2.new(1, 0, 0, 40)
                title.BackgroundTransparency = 1
                title.Text = "ATM Status"
                title.TextColor3 = Color3.fromRGB(255, 255, 255)
                title.TextScaled = true
                title.Font = Enum.Font.GothamBold
                title.TextStrokeTransparency = 0.75
                title.Parent = frame

                local titleGradient = Instance.new("UIGradient")
                titleGradient.Color = ColorSequence.new{
                    ColorSequenceKeypoint.new(0, Color3.fromRGB(255, 255, 255)),
                    ColorSequenceKeypoint.new(1, Color3.fromRGB(200, 200, 200))
                }
                titleGradient.Rotation = 90
                titleGradient.Parent = title

                local scrollingFrame = Instance.new("ScrollingFrame")
                scrollingFrame.Size = UDim2.new(1, -10, 1, -50)
                scrollingFrame.Position = UDim2.new(0, 5, 0, 45)
                scrollingFrame.BackgroundTransparency = 1
                scrollingFrame.ScrollBarThickness = 8
                scrollingFrame.ScrollBarImageColor3 = Color3.fromRGB(120, 120, 120)
                scrollingFrame.Parent = frame

                local uiListLayout = Instance.new("UIListLayout")
                uiListLayout.Parent = scrollingFrame
                uiListLayout.SortOrder = Enum.SortOrder.LayoutOrder
                uiListLayout.HorizontalAlignment = Enum.HorizontalAlignment.Center
                uiListLayout.VerticalAlignment = Enum.VerticalAlignment.Top
                uiListLayout.Padding = UDim.new(0, 5)

                local function updateATMStatus()
                    for _, child in ipairs(scrollingFrame:GetChildren()) do
                        if child:IsA("TextLabel") then
                            child:Destroy()
                        end
                    end

                    local ATMS = game:GetService("Workspace").Map:WaitForChild("ATMS")
                    local labels = {}

                    for i = 1, 15 do
                        local atmName = "ATM: " .. i
                        local atm = ATMS:FindFirstChild("ATM" .. i)

                        if atm then
                            local attachment = atm:FindFirstChild("Attachment")
                            if attachment then
                                local proximityPrompt = attachment:FindFirstChild("ProximityPrompt")
                                local textColor = Color3.fromRGB(255, 0, 0) 
                                if proximityPrompt and proximityPrompt.Enabled then
                                    textColor = Color3.fromRGB(0, 255, 0)  
                                end

                                local textLabel = Instance.new("TextLabel")
                                textLabel.Size = UDim2.new(1, -20, 0, 25)
                                textLabel.BackgroundTransparency = 0.1
                                textLabel.BackgroundColor3 = Color3.fromRGB(30, 30, 30)
                                textLabel.Text = atmName
                                textLabel.TextColor3 = textColor 
                                textLabel.TextScaled = true
                                textLabel.Font = Enum.Font.Gotham
                                textLabel.TextXAlignment = Enum.TextXAlignment.Left
                                textLabel.TextYAlignment = Enum.TextYAlignment.Center
                                textLabel.Parent = scrollingFrame

                                local labelCorner = Instance.new("UICorner")
                                labelCorner.CornerRadius = UDim.new(0, 6)
                                labelCorner.Parent = textLabel

                                local labelGradient = Instance.new("UIGradient")
                                labelGradient.Color = ColorSequence.new{
                                    ColorSequenceKeypoint.new(0, Color3.fromRGB(60, 60, 60)),
                                    ColorSequenceKeypoint.new(1, Color3.fromRGB(80, 80, 80))
                                }
                                labelGradient.Rotation = 90
                                labelGradient.Parent = textLabel
                                
                                table.insert(labels, textLabel)
                            end
                        end
                    end

                    local contentHeight = #labels * 30  
                    scrollingFrame.CanvasSize = UDim2.new(0, 0, 0, contentHeight)
                end

                updateATMStatus()

                local connection
                connection = game:GetService("RunService").Heartbeat:Connect(function()
                    if state then
                        updateATMStatus()
                    else
                        if connection then connection:Disconnect() end
                    end
                end)
            end
        else
            if screenGui then
                screenGui:Destroy()
            end
        end
    end
})

MainSection:AddToggle({
    Name = 'Atm Esp',
    Value = false,          -- Default state
    Flag = 'feature_toggle', -- Unique identifier
    Locked = false,         -- Prevent user changes
    Callback = function(state)
        loadstring(game:HttpGet('https://pastebin.com/raw/ikvvvwYW'))()
    end
})

MainSection:AddToggle({
    Name = 'Teleport to Active Atm',
    Value = false,          -- Default state
    Flag = 'feature_toggle', -- Unique identifier
    Locked = false,         -- Prevent user changes
    Callback = function(state)
        local player = game.Players.LocalPlayer
        local character = player.Character or player.CharacterAdded:Wait()
        local humanoidRootPart = character:WaitForChild("HumanoidRootPart")
        local camera = workspace.CurrentCamera

        local ATMS = {
            {name = "ATM1", cframe = CFrame.new(-33.1487, 3.7370, -299.5453), path = "ATM1"},
            {name = "ATM2", cframe = CFrame.new(538.4818, 3.7371, -349.0415), path = "ATM2"},
            {name = "ATM3", cframe = CFrame.new(497.8156, 3.7839, 405.5681), path = "ATM3"},
            {name = "ATM4", cframe = CFrame.new(236.1748, 3.1180, -165.3973), path = "ATM4"},
            {name = "ATM5", cframe = CFrame.new(-652.0219, 4.2857, 155.1690), path = "ATM5"},
            {name = "ATM6", cframe = CFrame.new(-455.1304, 4.3107, 370.8311), path = "ATM6"},
            {name = "ATM7", cframe = CFrame.new(-266.3022, 4.4058, -212.2364), path = "ATM7"},
            {name = "ATM8", cframe = CFrame.new(-10.4940, 3.7371, 233.9844), path = "ATM8"},
            {name = "ATM9", cframe = CFrame.new(717.0417, 3.8176, 413.7101), path = "ATM9"},
            {name = "ATM10", cframe = CFrame.new(-536.8209, 4.2857, -20.3541), path = "ATM10"},
            {name = "ATM11", cframe = CFrame.new(-652.021, 4.285, 155.169), path = "ATM11"},
            {name = "ATM12", cframe = CFrame.new(714.4320, 4.2857, -240.3657), path = "ATM12"},
            {name = "ATM13", cframe = CFrame.new(-314.9244, 3.8715, 145.9376), path = "ATM13"},
            {name = "ATM14", cframe = CFrame.new(-377.9388, 4.3107, -359.7116), path = "ATM14"},
            {name = "ATM15", cframe = CFrame.new(360.0960, 3.7371, -359.4165), path = "ATM15"},
        }

        for _, atm in ipairs(ATMS) do
            local atmPath = workspace:FindFirstChild("Map"):FindFirstChild("ATMS"):FindFirstChild(atm.path)
            if atmPath and atmPath:FindFirstChild("Attachment") then
                local proximityPrompt = atmPath.Attachment:FindFirstChild("ProximityPrompt")
                if proximityPrompt and proximityPrompt.Enabled then
                    
                    humanoidRootPart.CFrame = atm.cframe
                    
                    local cameraOffset = Vector3.new(0, 5, -10) 
                    camera.CFrame = CFrame.new(humanoidRootPart.Position + cameraOffset, atm.cframe.Position)

                    wait(0.2)
                    
                    fireproximityprompt(proximityPrompt, 1, true)
                    
                    return
                end
            end
        end
    end
})


local MainSection = GeneralTab:CreateSection({
    Name = '👤Character👤',
    Side = 'Left'
})

MainSection:AddButton({
    Name = 'Infinite Stamina',
    Callback = function()
         game.Players.LocalPlayer.Backpack.GlobalFunctions.Stamina.Value = 100
    end
})

MainSection:AddButton({
    Name = 'Infinite Zoom',
    Callback = function()
         getgenv().host = game:GetService'Players'.LocalPlayer

host.CameraMaxZoomDistance = math.huge
    end
})

MainSection:AddButton({
    Name = 'FPS Boost',
    Callback = function()
        --[[
MAX FPS BOOSTER  | TRULY DOGSHIT PS1 GRAPHICS

-no textures
-simple shadows
-simple water
-no particles, reflections, or post effects
-simplified hitboxes
-no rendering tiny parts (<5 studs)
--faster dex
-**no terrain at all** | replaced with a huge baseplate | press CTRL+BRACKETS to change the baseplate height

--]]

if not game:IsLoaded() then
	game.Loaded:Wait()
	wait(10)
end

local function check(inst)
	local class = inst.ClassName
	if class == "Decal" or class == "Texture" then 
		inst.Texture = ""
	elseif class == "SpecialMesh" then 
		inst.TextureId = ""
	elseif class == "ParticleEmitter" then
		inst.Texture = ""
		inst.Rate = 0
	elseif inst:IsA("BasePart") then 
		inst.Material = "SmoothPlastic"
		inst.Reflectance = 0
		inst.CastShadow = false
		if class == "MeshPart" then 
			inst.TextureID = ""
			inst.CollisionFidelity = "Hull"
		elseif class == "UnionOperation" then
			inst.CollisionFidelity = "Hull"
		end
		if inst.Anchored and inst.Size.Magnitude < 5 then
			inst.Transparency = 1
			inst.CanCollide = false
			--inst:Destroy()
		end
	end
end

local function removeDups(children)
	if #children > 99 then
		local myname = tostring(game:GetService("Players").LocalPlayer)
		local fake = {Name = myname}
		for i=1,#children do
			local name1 = children[i].Name
			if name1 ~= myname and name1 ~= "Terrain" then
				local moved = false
				for j=i+1,#children do
					if children[j].Name == name1 then
						moved = true
						children[j].Parent = workspace.Terrain
						children[j] = fake
					end
				end
				if moved then 
					children[i].Parent = workspace.Terrain
				end
			end
		end
	end
end

settings().Rendering.QualityLevel = Enum.QualityLevel.Level01
UserSettings():GetService("UserGameSettings").SavedQualityLevel = Enum.SavedQualitySetting.QualityLevel1
settings().Rendering.EagerBulkExecution = false
settings().Network.IncomingReplicationLag = -1000

workspace:WaitForChild("Terrain")
workspace.Terrain.WaterReflectance = 0
workspace.Terrain.WaterWaveSize = 0
workspace.Terrain.WaterWaveSpeed = 0
workspace.Terrain.WaterTransparency = 0

game:GetService("Lighting").GlobalShadows = false

workspace.Terrain:Clear()
local plates = {}
if not workspace:FindFirstChild("Baseplate") then
    for x=-1,1,2 do
        for z=-1,1,2 do
            local part = Instance.new("Part")
            part.Size = Vector3.new(2048,5,2048)
            part.CFrame = CFrame.new(1024*x,-5,1024*z)
            part.Anchored=true
            part.Material="SmoothPlastic"
            part.Color = Color3.new(0.36,0.6,0.3)
            part.Name = "Baseplate"
            part.Parent= workspace
			plates[#plates+1]= part
        end
    end
end
local UIS = game:GetService("UserInputService")
UIS.InputBegan:Connect(function(input,gpe)
    if gpe==false and UIS:IsKeyDown("LeftControl") then 
        if input.KeyCode==Enum.KeyCode.RightBracket then 
            for _,part in ipairs(plates) do
                part.CFrame=part.CFrame+Vector3.new(0,2.5,0)
            end
        elseif input.KeyCode==Enum.KeyCode.LeftBracket then 
            for _,part in ipairs(plates) do 
                part.CFrame=part.CFrame-Vector3.new(0,2.5,0)
            end
        end
    end
end)
wait(0.3)

while true do
	for _,v in ipairs(game:GetService("Lighting"):GetDescendants()) do
		if v:IsA("PostEffect") then
			v.Enabled = false
		end
	end
	local des = workspace:GetDescendants()
	for i=1,#des do
		check(des[i])
	end
	wait(0.3)
	--faster dex
	removeDups(workspace:GetChildren())

	wait(600)
end
    end
})

MainSection:AddButton({
    Name = 'Jerk Off',
    Callback = function()
         loadstring(game:HttpGet("https://pastefy.app/YZoglOyJ/raw"))()
    end
})

MainSection:AddButton({
    Name = 'BTools',
    Callback = function()
         backpack = game:GetService("Players").LocalPlayer.Backpack

hammer = Instance.new("HopperBin")
hammer.Name = "Hammer"
hammer.BinType = 4
hammer.Parent = backpack
    end
})

MainSection:AddButton({
    Name = 'Instant Prompt',
    Callback = function()
 --[[
	WARNING: Heads up! This script has not been verified by ScriptBlox. Use at your own risk!
]]
for i,v in ipairs(game:GetService("Workspace"):GetDescendants()) do
 if v.ClassName == "ProximityPrompt" then
  v.HoldDuration = 0
 end
end
    
    end
})


MainSection:AddToggle({
    Name = 'Faster WalkSpeed',
    Value = false,          -- Default state
    Flag = 'feature_toggle', -- Unique identifier
    Locked = false,         -- Prevent user changes
    Keybind = {             -- Optional keybind
        Flag = 'feature_key',
        Mode = 'Toggle',    -- 'Toggle' or 'Hold'
        Value = Enum.KeyCode.X
    },
    Callback = function(state)
        game.Players.LocalPlayer.Character.Humanoid.WalkSpeed = 21
    end
})

MainSection:AddButton({
    Name = 'Reset Walkspeed',
    Callback = function()
        game.Players.LocalPlayer.Character.Humanoid.WalkSpeed = 13
    end
})

---\\Spoof Section (Main Tab)//---
getgenv().name = ""
getgenv().isSpoofEnabled = false
getgenv().isCharacterSpoofEnabled = false
getgenv().isFriendSpoofEnabled = false
local originalTexts = {}
local originalNames = {}
local Players = game:GetService("Players")
local Plr = Players.LocalPlayer

local function updateTextLabel(Value, player)
    if getgenv().isSpoofEnabled or (getgenv().isFriendSpoofEnabled and Plr:IsFriendsWith(player.UserId)) then
        if not originalTexts[Value] then
            originalTexts[Value] = Value.Text
        end
        local has = string.find(Value.Text, player.Name)
        if has then
            Value.Text = Value.Text:gsub(player.Name, getgenv().name)
        end
    else
        if originalTexts[Value] then
            Value.Text = originalTexts[Value]
            originalTexts[Value] = nil
        end
    end

    Value:GetPropertyChangedSignal("Text"):Connect(function()
        if getgenv().isSpoofEnabled or (getgenv().isFriendSpoofEnabled and Plr:IsFriendsWith(player.UserId)) then
            Value.Text = Value.Text:gsub(player.Name, getgenv().name)
        else
            if originalTexts[Value] then
                Value.Text = originalTexts[Value]
                originalTexts[Value] = nil
            end
        end
    end)
end

local function applyTextLabelSpoof()
    for _, Value in next, game:GetDescendants() do 
        if Value:IsA("TextLabel") then 
            updateTextLabel(Value, Plr)
            for _, friend in ipairs(Players:GetPlayers()) do
                if friend ~= Plr and Plr:IsFriendsWith(friend.UserId) then
                    updateTextLabel(Value, friend)
                end
            end
        end
    end
end

game.DescendantAdded:Connect(function(Value)
    if Value:IsA("TextLabel") then 
        updateTextLabel(Value, Plr)
    end
end)

MainSection:AddTextbox({
  Name = "",
    Value = "Enter a name",
    Callback = function(input)
        getgenv().name = input
        applyTextLabelSpoof()
    end
}) 

MainSection:AddToggle({
   Name = "| Spoof User/Display Name",
    Flag = "LPSection_SpoofUser/DisplayName",
    Callback = function(state)
        getgenv().isSpoofEnabled = state
        applyTextLabelSpoof()
    end
})

local function spoofCharacterName(player)
    local characterNameTag = workspace.Characters:FindFirstChild(player.Name)
    if characterNameTag and characterNameTag:FindFirstChild("Head") and characterNameTag.Head:FindFirstChild("NameTag") then
        local mainFrame = characterNameTag.Head.NameTag:FindFirstChild("MainFrame")
        if mainFrame and mainFrame:FindFirstChild("NameLabel") then
            mainFrame.NameLabel.Text = getgenv().name  
        end
    end
end

local function applyCharacterNameSpoof()
    if getgenv().isCharacterSpoofEnabled or getgenv().isFriendSpoofEnabled then
        spoofCharacterName(Plr)
        for _, friend in ipairs(Players:GetPlayers()) do
            if friend ~= Plr and Plr:IsFriendsWith(friend.UserId) then
                spoofCharacterName(friend)
            end
        end
    end
end

MainSection:AddToggle({
  Name = "| Spoof Overhead Name",
    Flag = "LPSection_SpoofOverheadName",
    Callback = function(state)
        getgenv().isCharacterSpoofEnabled = state
        applyCharacterNameSpoof()

        Plr.CharacterAdded:Connect(function()
            if getgenv().isCharacterSpoofEnabled then
                wait(0.1) 
                applyCharacterNameSpoof()
            end
        end)
    end
})

MainSection:AddToggle({
Name = "| Spoof Friends List",
    Flag = "LPSection_SpoofFriendsList",
    Callback = function(state)
        getgenv().isFriendSpoofEnabled = state
        applyTextLabelSpoof()
        applyCharacterNameSpoof()

        if state then
            for _, friend in ipairs(Players:GetPlayers()) do
                if friend ~= Plr then
                    originalNames[friend.UserId] = friend.Name
                    updateTextLabel(friend, Plr)
                    spoofCharacterName(friend)
                end
            end

            Players.PlayerAdded:Connect(function(player)
                if Plr:IsFriendsWith(player.UserId) then
                    originalNames[player.UserId] = player.Name
                    applyTextLabelSpoof()
                    applyCharacterNameSpoof()
                end
            end)
        else
            for _, friend in ipairs(Players:GetPlayers()) do
                if friend ~= Plr and originalNames[friend.UserId] then
                    local originalName = originalNames[friend.UserId]
                    originalTexts[friend] = nil
                    if friend.Character and friend.Character:FindFirstChild("Head") and friend.Character.Head:FindFirstChild("NameTag") then
                        local mainFrame = friend.Character.Head.NameTag:FindFirstChild("MainFrame")
                        if mainFrame and mainFrame:FindFirstChild("NameLabel") then
                            mainFrame.NameLabel.Text = originalName
                        end
                    end
                    for _, Value in ipairs(friend:GetDescendants()) do
                        if Value:IsA("TextLabel") then
                            Value.Text = originalTexts[Value] or originalName
                        end
                    end
                    originalNames[friend.UserId] = nil
                end
            end
        end
    end
})
local MainTab = Window:CreateTab({Name = 'Combat'})

local MainSection = MainTab:CreateSection({
    Name = 'Aimbot E',
    Side = 'Right'  -- 'Left' or 'Right'
})

MainSection:AddButton({
    Name = 'Aimbot',
    Callback = function()
        getgenv().OldAimPart = "Head"
getgenv().AimPart = "Head" -- For R15 Games: {UpperTorso, LowerTorso, HumanoidRootPart, Head} | For R6 Games: {Head, Torso, HumanoidRootPart}  
    getgenv().AimlockKey = "e"
    getgenv().AimRadius = 100 -- How far away from someones character you want to lock on at
    getgenv().ThirdPerson = true 
    getgenv().FirstPerson = true
    getgenv().TeamCheck = false -- Check if Target is on your Team (True means it wont lock onto your teamates, false is vice versa) (Set it to false if there are no teams)
    getgenv().PredictMovement = true -- Predicts if they are moving in fast velocity (like jumping) so the aimbot will go a bit faster to match their speed 
    getgenv().PredictionVelocity = 10
    getgenv().CheckIfJumped = true
    getgenv().Smoothness = false
    getgenv().SmoothnessAmount = 0.5

    local Players, Uis, RService, SGui = game:GetService"Players", game:GetService"UserInputService", game:GetService"RunService", game:GetService"StarterGui";
    local Client, Mouse, Camera, CF, RNew, Vec3, Vec2 = Players.LocalPlayer, Players.LocalPlayer:GetMouse(), workspace.CurrentCamera, CFrame.new, Ray.new, Vector3.new, Vector2.new;
    local Aimlock, MousePressed, CanNotify = true, false, false;
    local AimlockTarget;
    local OldPre;
    

    
    getgenv().WorldToViewportPoint = function(P)
        return Camera:WorldToViewportPoint(P)
    end
    
    getgenv().WorldToScreenPoint = function(P)
        return Camera.WorldToScreenPoint(Camera, P)
    end
    
    getgenv().GetObscuringObjects = function(T)
        if T and T:FindFirstChild(getgenv().AimPart) and Client and Client.Character:FindFirstChild("Head") then 
            local RayPos = workspace:FindPartOnRay(RNew(
                T[getgenv().AimPart].Position, Client.Character.Head.Position)
            )
            if RayPos then return RayPos:IsDescendantOf(T) end
        end
    end
    
    getgenv().GetNearestTarget = function()
        -- Credits to whoever made this, i didnt make it, and my own mouse2plr function kinda sucks
        local players = {}
        local PLAYER_HOLD  = {}
        local DISTANCES = {}
        for i, v in pairs(Players:GetPlayers()) do
            if v ~= Client then
                table.insert(players, v)
            end
        end
        for i, v in pairs(players) do
            if v.Character ~= nil then
                local AIM = v.Character:FindFirstChild("Head")
                if getgenv().TeamCheck == true and v.Team ~= Client.Team then
                    local DISTANCE = (v.Character:FindFirstChild("Head").Position - game.Workspace.CurrentCamera.CFrame.p).magnitude
                    local RAY = Ray.new(game.Workspace.CurrentCamera.CFrame.p, (Mouse.Hit.p - game.Workspace.CurrentCamera.CFrame.p).unit * DISTANCE)
                    local HIT,POS = game.Workspace:FindPartOnRay(RAY, game.Workspace)
                    local DIFF = math.floor((POS - AIM.Position).magnitude)
                    PLAYER_HOLD[v.Name .. i] = {}
                    PLAYER_HOLD[v.Name .. i].dist= DISTANCE
                    PLAYER_HOLD[v.Name .. i].plr = v
                    PLAYER_HOLD[v.Name .. i].diff = DIFF
                    table.insert(DISTANCES, DIFF)
                elseif getgenv().TeamCheck == false and v.Team == Client.Team then 
                    local DISTANCE = (v.Character:FindFirstChild("Head").Position - game.Workspace.CurrentCamera.CFrame.p).magnitude
                    local RAY = Ray.new(game.Workspace.CurrentCamera.CFrame.p, (Mouse.Hit.p - game.Workspace.CurrentCamera.CFrame.p).unit * DISTANCE)
                    local HIT,POS = game.Workspace:FindPartOnRay(RAY, game.Workspace)
                    local DIFF = math.floor((POS - AIM.Position).magnitude)
                    PLAYER_HOLD[v.Name .. i] = {}
                    PLAYER_HOLD[v.Name .. i].dist= DISTANCE
                    PLAYER_HOLD[v.Name .. i].plr = v
                    PLAYER_HOLD[v.Name .. i].diff = DIFF
                    table.insert(DISTANCES, DIFF)
                end
            end
        end
        
        if unpack(DISTANCES) == nil then
            return nil
        end
        
        local L_DISTANCE = math.floor(math.min(unpack(DISTANCES)))
        if L_DISTANCE > getgenv().AimRadius then
            return nil
        end
        
        for i, v in pairs(PLAYER_HOLD) do
            if v.diff == L_DISTANCE then
                return v.plr
            end
        end
        return nil
    end
    
    Mouse.KeyDown:Connect(function(a)
        if not (Uis:GetFocusedTextBox()) then 
            if a == AimlockKey and AimlockTarget == nil then
                pcall(function()
                    if MousePressed ~= true then MousePressed = true end 
                    local Target;Target = GetNearestTarget()
                    if Target ~= nil then 
                        AimlockTarget = Target
                    end
                end)
            elseif a == AimlockKey and AimlockTarget ~= nil then
                if AimlockTarget ~= nil then AimlockTarget = nil end
                if MousePressed ~= false then 
                    MousePressed = false 
                end
            end
        end
    end)
    
    RService.RenderStepped:Connect(function()
        if getgenv().ThirdPerson == true and getgenv().FirstPerson == true then 
            if (Camera.Focus.p - Camera.CoordinateFrame.p).Magnitude > 1 or (Camera.Focus.p - Camera.CoordinateFrame.p).Magnitude <= 1 then 
                CanNotify = true 
            else 
                CanNotify = false 
            end
        elseif getgenv().ThirdPerson == true and getgenv().FirstPerson == false then 
            if (Camera.Focus.p - Camera.CoordinateFrame.p).Magnitude > 1 then 
                CanNotify = true 
            else 
                CanNotify = false 
            end
        elseif getgenv().ThirdPerson == false and getgenv().FirstPerson == true then 
            if (Camera.Focus.p - Camera.CoordinateFrame.p).Magnitude <= 1 then 
                CanNotify = true 
            else 
                CanNotify = false 
            end
        end
        if Aimlock == true and MousePressed == true then 
            if AimlockTarget and AimlockTarget.Character and AimlockTarget.Character:FindFirstChild(getgenv().AimPart) then 
                if getgenv().FirstPerson == true then
                    if CanNotify == true then
                        if getgenv().PredictMovement == true then
                            if getgenv().Smoothness == true then
                                --// The part we're going to lerp/smoothen \\--
                                local Main = CF(Camera.CFrame.p, AimlockTarget.Character[getgenv().AimPart].Position + AimlockTarget.Character[getgenv().AimPart].Velocity/PredictionVelocity)
                                
                                --// Making it work \\--
                                Camera.CFrame = Camera.CFrame:Lerp(Main, getgenv().SmoothnessAmount, Enum.EasingStyle.Elastic, Enum.EasingDirection.InOut)
                            else
                                Camera.CFrame = CF(Camera.CFrame.p, AimlockTarget.Character[getgenv().AimPart].Position + AimlockTarget.Character[getgenv().AimPart].Velocity/PredictionVelocity)
                            end
                        elseif getgenv().PredictMovement == false then 
                            if getgenv().Smoothness == true then
                                --// The part we're going to lerp/smoothen \\--
                                local Main = CF(Camera.CFrame.p, AimlockTarget.Character[getgenv().AimPart].Position)

                                --// Making it work \\--
                                Camera.CFrame = Camera.CFrame:Lerp(Main, getgenv().SmoothnessAmount, Enum.EasingStyle.Elastic, Enum.EasingDirection.InOut)
                            else
                                Camera.CFrame = CF(Camera.CFrame.p, AimlockTarget.Character[getgenv().AimPart].Position)
                            end
                        end
                    end
                end
            end
        end
         if CheckIfJumped == true then
       if AimlockTarget.Character.HuDDDDDDDDDDWmanoid.FloorMaterial == Enum.Material.Air then
    
           getgenv().AimPart = "UpperTorso"
       else
         getgenv().AimPart = getgenv().OldAimPart

       end
    end
end)
   end,
})

MainSection:AddToggle({
    Name = "Camlock (E)",
    Value = false,
    Flag = "WeaponStatsToggle", 
    Callback = function(Value)
        --[[
	WARNING: Heads up! This script has not been verified by ScriptBlox. Use at your own risk!
]]
getgenv().NemesisPreBeta = {
    ["Settings"] = {
        Disabling = {Toggle = false, Keybind = "H"},
        UpdateTickDelay = 0.05
    },
    ["Camlock"] = {
        Toggling = {
            Enable = true, 
            Keybind = "E"
        },
        Settings = {
            Prediction = { 
                true, 
                999.999, 
                false, 
                .003
            },
            Smoothing = {
                smoothness = true, 
                x = 1, 
                y = 1
            },
            OffSets = {
                Jump = {
                    Enable = false, 
                    [1] = Vector3.new(0, 3, 0)
                }
            }
        },
        Conditions = {
            Player = {
                WallCheck = false, 
                Grabbed = false, 
                Knocked = false, 
                CrewID = false
            },
            BodyParts = {"HumanoidRootPart", "Head"}
        }
    },
    ["Silent"] = {
        Toggling = { Enable = false },
        Settings = {
            Prediction = { true , 0.11934 , false, 0.003 },
            HitChance = 100,
            Resolver = true,
            OffSets = {
                Jump = {
                    Enable = false, 
                    [1] = Vector3.new(0, 0, 0)
                }
            }
        },
        Conditions = {
            Player = { WallCheck = false, Grabbed = false, Knocked = false, CrewID = false },
            BodyParts = {"HumanoidRootPart", "UpperTorso", "Head"}
        }
    },
    ["Field Of View"] = {
        Enable = true, 
        Size = 1000, 
        Color = Color3.fromRGB(255, 255, 255), 
    },
    ["Miscs"] = {
        ["Sorting"] = {
            Toggled = false,
            Key = "F",
            alphabetically = true,
            Ammo = false,
            Custom = {
                Enable = false,
                List = {[1] = "[Revolver]", [2] = "[Chicken]"} -- // etc
            }
        },
        ["Animation"] = {
            Enable = true,
            Animations = {["Greet"] = {[1] = false, [2] = "V"}}
        }
    }
}





local DUpvalue, Round, V3, V2, CF, Rservice, UserInput, Ping, Mouse, backpack  = debug.getupvalue, math.round, Vector3.new, Vector2.new, CFrame.new, game:GetService("RunService"), game:GetService("UserInputService"), game:GetService("Stats").PerformanceStats.Ping, game:GetService("Players").LocalPlayer:GetMouse(), game:GetService("Players").LocalPlayer.Backpack
local Players, Self, Character, Camera = game:GetService("Players"), game:GetService("Players").LocalPlayer, game:GetService("Players").LocalPlayer.Character or  game:GetService("Players").LocalPlayer.CharacterAdded:Wait(), game:GetService("Workspace").CurrentCamera
local idx, endp


local Storage = {
    Drawings = {},
    Connections = {},
    targets = {
        [1] = nil,
        [2] = nil
    },
    ValuePosition = nil,
    bodyparts = {
        [1] = "",
        [2] = ""
    },
    update_tick = tick(),
    etc = {
        Ctoggled = false,
        Mtoggled = false
    },
    items = {}
}



function NewConnection(type, callback)
    local connection = type:Connect(callback)
    Storage.Connections[#Storage.Connections+1] = connection
    return connection
end

function Chance(chance, maxchance)
    return math.random(maxchance) <= chance
end


function Thread(Function, ...)
    local co
    local success, result

    if Function ~= nil then
        co = coroutine.create(Function)
        success, result = coroutine.resume(co, ...)
    end
    if success ~= nil and co ~= nil and Function ~= nil then
        return result
    end
end


function wallcheck(origin)
    local parts = Camera:GetPartsObscuringTarget({origin.Position,  Character.HumanoidRootPart.Position}, {Camera, Character, origin.Parent})
    if #parts == 0 then
        return true
    end
    return false
end

function Grabbed(player)
    if player.Character ~= nil  then
        return not player.Character:FindFirstChild("GRABBING_CONSTRAINT")
    end
end

function Knocked(player)
    if player.Character ~= nil  then
        return player.Character.BodyEffects["K.O"].Value ~= true
    end
end


local pingHistory = {}
local lastPingUpdateTime = tick()



function GetPrediction()
    local currentPing = Ping:GetValue() * 0.003
    if getgenv().NemesisPreBeta.Camlock.Settings.Prediction[3] or getgenv().NemesisPreBeta.Silent.Settings.Prediction[3] then
        return currentPing
    else
        return getgenv().NemesisPreBeta.Camlock.Settings.Prediction[2] and getgenv().NemesisPreBeta.Silent.Settings.Prediction[2]
    end
end

function Crew(player)
    if game.Players.LocalPlayer:FindFirstChild("DataFolder"):FindFirstChild("Information"):FindFirstChild("Crew") then
        local SelfCrewValue =  game.Players.LocalPlayer:FindFirstChild("DataFolder"):FindFirstChild("Information"):FindFirstChild("Crew")
        if SelfCrewValue.Value ~= 0 then
            if player:FindFirstChild("DataFolder"):FindFirstChild("Information"):FindFirstChild("Crew")  then
                local Enimy = player:FindFirstChild("DataFolder"):FindFirstChild("Information"):FindFirstChild("Crew")
                if Enimy.Value == SelfCrewValue.Value then
                    return false
                end
            end
        end
    end
    return true
end



function Closespart(player, hitboxes)
    local closestPart
    local closestDistanc = math.huge
    for _, hitbox in pairs(hitboxes) do
        local part = player.Character:FindFirstChild(hitbox)
        if part then
            local pos = Camera:WorldToViewportPoint(part.Position)
            local distance = (UserInput:GetMouseLocation() - V2(pos.X, pos.Y)).Magnitude
            if distance < closestDistanc then
                closestPart = part
                closestDistanc = distance
            end
        end
    end
    return closestPart
end



function isInCustomList(toolName)
    for _, customName in ipairs(getgenv().NemesisPreBeta.Miscs.Sorting.Custom.List) do
        if toolName == customName then
            return true
        end
    end
    return false
end


function GetClosest(table)
    local MaxDistance = getgenv().NemesisPreBeta["Field Of View"].Enable and getgenv().NemesisPreBeta["Field Of View"].Size or math.huge
    local Target

    for i,v in pairs(Players:GetPlayers()) do
        if v ~= Self and v.Character ~= nil and v.Character:FindFirstChild("HumanoidRootPart") and v.Character:FindFirstChild("Head") then
            local ViewPort, Visible = Camera:WorldToViewportPoint(v.Character.HumanoidRootPart.Position)
            local Mag = (UserInput:GetMouseLocation() - Vector2.new(ViewPort.X, ViewPort.Y)).Magnitude
            if MaxDistance > Mag and Visible and (
                (table.WallCheck and wallcheck(v.Character.HumanoidRootPart)) or true and
                (table.Grabbed and Grabbed(v)) or true and
                (table.Knocked and Knocked(v)) or true and
                (table.CrewID and Crew(v)) or true 
            ) then
                MaxDistance = Mag
                Target = v
            end
        end
    end
    return Target
end

function Velocity(Target, method)
    if method == true then
        local pos = Target.Character.HumanoidRootPart.Position
        local lastTime = tick()
        local currentPos, currentTime
        local connection
        connection =
            game:GetService("RunService").Heartbeat:Connect(
            function()
                currentPos = Target.Character.HumanoidRootPart.Position
                currentTime = tick()
                connection:Disconnect()
            end
        )
        wait(0.01)
        local velocity = (currentPos - pos) / (currentTime - lastTime)
        return Vector3.new(math.floor(velocity.X), math.floor(velocity.Y), math.floor(velocity.Z))
    else
        return Target.character:FindFirstChild("HumanoidRootPart").AssemblyLinearVelocity
    end
end

function playAnimation(animationName)
    local args = {
        [1] = "AnimationPack",
        [2] = animationName,
    }
    game:GetService("ReplicatedStorage").MainEvent:FireServer(unpack(args))
end


-- // updates

function UpdateSilent()
    local SilentTable = getgenv().NemesisPreBeta.Silent
    if SilentTable.Toggling.Enable then
        Storage.targets[2] = GetClosest(SilentTable.Conditions.Player)
        if Storage.targets[2] ~= nil and Storage.targets[2].Character ~= nil and Storage.targets[2].Character:FindFirstChild("HumanoidRootPart") then
            Storage.bodyparts[2] =  tostring(Closespart(Storage.targets[2], SilentTable.Conditions.BodyParts))
            local position = Storage.targets[2].Character[Storage.bodyparts[2]].Position
            if SilentTable.Settings.OffSets.Jump.Enable and Storage.targets[2].Character:FindFirstChildOfClass("Humanoid"):GetState() == Enum.HumanoidStateType.Freefall then
                position = position + SilentTable.Settings.OffSets.Jump[1]
            end
            Storage.CFposition = position + (SilentTable.Settings.Prediction and Velocity(Storage.targets[2], SilentTable.Settings.Resolver) * GetPrediction() or 0)
        end
    end
end


function UpdateCamlock()
    local CamLockTable = getgenv().NemesisPreBeta.Camlock
    if Storage.etc.Ctoggled and CamLockTable.Toggling.Enable and Storage.targets[1] ~= nil and Storage.targets[1].Character ~= nil then
        local position = Storage.targets[1].Character[Storage.bodyparts[1]].Position

        if CamLockTable.Settings.OffSets.Jump.Enable and Storage.targets[1].Character:FindFirstChildOfClass("Humanoid"):GetState() == Enum.HumanoidStateType.Freefall then
            position = position + CamLockTable.Settings.OffSets.Jump[1]
        end

        if CamLockTable.Settings.Smoothing.enable then
            local goal = CFrame.new(Camera.CFrame.Position, position + (CamLockTable.Settings.Prediction[1] * GetPrediction() or Vector3.new()))
            Camera.CFrame = Camera.CFrame:Lerp(goal, CamLockTable.Settings.Smoothing.x, CamLockTable.Settings.Smoothing.y)
        else
            local prediction = CamLockTable.Settings.Prediction[1] and Storage.targets[1].Character.HumanoidRootPart.AssemblyLinearVelocity * GetPrediction() or Vector3.new()
            Camera.CFrame = CFrame.new(Camera.CFrame.Position, position + prediction)
        end
    end
end

do -- main connection

    NewConnection(UserInput.InputBegan, function(key, wtv)
        if key.KeyCode == Enum.KeyCode[getgenv().NemesisPreBeta.Camlock.Toggling.Keybind:upper()] and not wtv then
            if getgenv().NemesisPreBeta.Camlock.Toggling.Enable then
                Storage.etc.Ctoggled = not Storage.etc.Ctoggled
                Storage.targets[1] = GetClosest(getgenv().NemesisPreBeta.Camlock.Conditions.Player)

                if  Storage.targets[1] and  Storage.targets[1].Character then
                    Storage.bodyparts[1] = tostring(Closespart(Storage.targets[1], getgenv().NemesisPreBeta.Camlock.Conditions.BodyParts))

                end
            else
                if  Storage.targets[1] ~= nil then
                    Storage.targets[1] = nil
                end
            end
        end
    end)

    NewConnection(UserInput.InputBegan, function(key, wtv)
        if getgenv().NemesisPreBeta.Settings.Disabling.Toggle and key.KeyCode == Enum.KeyCode[getgenv().NemesisPreBeta.Settings.Disabling.Keybind:upper()]  and not wtv then
            for i,v in pairs(Storage.Connections) do
                if v then
                    v:Disconnect()
                end
            end
            for i,v in pairs(Storage.Drawings) do
                if v and v.__OBJECT_EXISTS then
                    print("f")
                end
            end
        end
    end)

    NewConnection(UserInput.InputBegan, function(key, wtv)
        if getgenv().NemesisPreBeta.Miscs.Sorting.Toggled and key.KeyCode == Enum.KeyCode[getgenv().NemesisPreBeta.Miscs.Sorting.Key:upper()] and not wtv then
            local items = {}

            if getgenv().NemesisPreBeta.Miscs.Sorting.Custom.Enable then
                for _, customName in ipairs(getgenv().NemesisPreBeta.Miscs.Sorting.Custom.List) do
                    for _, item in pairs(backpack:GetChildren()) do
                        if item:IsA("Tool") and item.Name == customName then
                            table.insert(items, 1, item)
                            break
                        end
                    end
                end
            end
            
            for _, item in pairs(backpack:GetChildren()) do
                if item:IsA("Tool") and (not getgenv().NemesisPreBeta.Miscs.Sorting.Custom.Enable or not isInCustomList(item.Name)) then
                    table.insert(items, item)
                end
            end
            
            if getgenv().NemesisPreBeta.Miscs.Sorting.alphabetically and not getgenv().NemesisPreBeta.Miscs.Sorting.Custom.Enable then
                table.sort(items, function(a, b)
                    return a.Name < b.Name
                end)
            end
            
            if getgenv().NemesisPreBeta.Miscs.Sorting.Ammo and not getgenv().NemesisPreBeta.Miscs.Sorting.Custom.Enable then
                table.sort(items, function(a, b)
                    return a.Value > b.Value
                end)
            end

            for _, item in ipairs(items) do
                item.Parent = nil
                wait(0.01)
                item.Parent = backpack
            end

        end
    end)

    NewConnection(UserInput.InputBegan, function(key, wtv)
        if getgenv().NemesisPreBeta.Miscs.Animation.Enable and not wtv then
            for animationName, animationData in pairs(getgenv().NemesisPreBeta.Miscs.Animation.Animations) do
                if animationData[1] and key.KeyCode == Enum.KeyCode[animationData[2]] then
                    playAnimation(animationName)
                    break
                end
            end
        end
    end)




    NewConnection(Rservice.Heartbeat, function()

            --//  camlock
            Thread(UpdateCamlock())

            --// Silent UPDATE
            Thread(UpdateSilent())

    end)
end


    for connection, index in next, getconnections(workspace.CurrentCamera.Changed) do
        index:Disable()
    end
    for connection, index in next, getconnections(workspace.CurrentCamera:GetPropertyChangedSignal("CFrame")) do
        index:Disable()
    end


local oldIndex
oldIndex = hookmetamethod(game, "__index", function(t, k)
	if t:IsA("Mouse") and k == "Hit" or k == "Target" then
		if  getgenv().NemesisPreBeta.Silent.Toggling.Enable and Chance(getgenv().NemesisPreBeta.Silent.Settings.HitChance, 100) and Storage.targets[2] ~= nil then
			local Hit = CFrame.new(Storage.CFposition)
			return (k == "Hit" and Hit)
		end
	end
	return oldIndex(t, k)
end)
   end,
})

MainSection:AddToggle({
    Name = 'Hitbox',
    Value = false,          -- Default state
    Flag = 'feature_toggle', -- Unique identifier
    Locked = false,         -- Prevent user changes
    Callback = function(state)
        for k,v in next, game:GetService('Players'):GetChildren() do 
oghead = v.Character:FindFirstChild('Head')
if oghead then 
oghead.Size = Vector3.new(2,2,2,2) 
game.Players.LocalPlayer.Character.Head.Size = Vector3.new(2,2,2,2)
end
end
    end
})

local MainSection = MainTab:CreateSection({
    Name = 'Infinite Ammo',
    Side = 'Right'  -- 'Left' or 'Right'
})
local Players = game:GetService("Players")


local isToggled = false


local function continuouslyUpdateWeaponStats(player)
    while isToggled do 
        local backpack = player:FindFirstChild("Backpack")
        if backpack then
            -- Loop through all items in the backpack
            for _, item in ipairs(backpack:GetChildren()) do
                if item:IsA("Tool") then 
                     if item:FindFirstChild("Ammo") and item:FindFirstChild("Mag") then
                        item.Ammo.Value = 18
                        item.Mag.Value = 10
                    end
                end
            end
        end
        wait(0) 
    end
end


MainSection:AddToggle({
    Name = "Infinite Ammo",
    Value = false,
    Flag = "WeaponStatsToggle", 
    Callback = function(Value)
        isToggled = Value 
        if isToggled then
            
            for _, player in ipairs(Players:GetPlayers()) do
                task.spawn(function()
                    continuouslyUpdateWeaponStats(player)
                end)
            end
        end
    end,
})