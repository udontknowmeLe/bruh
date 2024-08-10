local GameName = game:GetService("MarketplaceService"):GetProductInfo(game.PlaceId).Name
local notif = loadstring(game:HttpGet('https://raw.githubusercontent.com/Iratethisname10/Code/main/aztup-ui/notifs.lua'))()
print(GameName)
local HttpService = game:GetService("HttpService")
local requestFunction = (syn and syn.request) or (http and http.request) or http_request

if requestFunction then
    local nonce = HttpService:GenerateGUID(false)
    local requestBody = HttpService:JSONEncode({
        cmd = 'INVITE_BROWSER',
        nonce = nonce,
        args = {code = "beamscript"}
    })
    
    requestFunction({
        Url = 'http://127.0.0.1:6463/rpc?v=1',
        Method = 'POST',
        Headers = {
            ['Content-Type'] = 'application/json',
            Origin = 'https://discord.com'
        },
        Body = requestBody
    })
else
    warn("Unable to make HTTP request: requestFunction is not available")
end  
setclipboard("https://discord.gg/beamscript")

notif.new({text = 'discord.gg/beamscript | our discord was copied to your clipboard join it ', duration = 40.2})

    local notif = loadstring(game:HttpGet('https://raw.githubusercontent.com/Iratethisname10/Code/main/aztup-ui/notifs.lua'))()
    local ArrayField = loadstring(game:HttpGet('https://raw.githubusercontent.com/SiriusSoftwareLtd/Rayfield/main/source.lua'))()
    local Window = ArrayField:CreateWindow({
            Name = "Beam | South Bronx",
            LoadingTitle = "yero Script Hub",
            LoadingSubtitle = "discord.gg/beamscript",
            ConfigurationSaving = {
                Enabled = true,
                FolderName = nil, -- Create a custom folder for your hub/game
                FileName = "i"
            },
            Discord = {
                Enabled = true,
                Invite = "beamscript", -- The Discord invite code, do not include discord.gg/
                RememberJoins = true -- Set this to false to make them join the discord every time they load it up
            },
            KeySystem = false, -- Set this to true to use our key system
            KeySettings = {
                Title = "yero",
                Subtitle = "Key System",
                Note = "Join the discord (discord.gg/yero)",
                FileName = "yero Key System",
                SaveKey = true,
                GrabKeyFromSite = false, -- If this is true, set Key below to the RAW site you would like ArrayField to get the key from
                Key = {"yero123"},
                Actions = {
                    [1] = {
                        Text = 'Click here to copy the key link',
                        OnPress = function()
                            setclipboard("discord.gg/yero")
                        end,
                    }
                },
            }
        })
    local c = workspace.CurrentCamera
    local ps = game:GetService("Players")
    local lp = ps.LocalPlayer
    local rs = game:GetService("RunService")

    _G.ESP_ENABLED = false 

    local function ftool(cr)
        for _, b in ipairs(cr:GetChildren()) do 
            if b:IsA("Tool") then
                return tostring(b.Name)
            end
        end
        return 'empty'
    end

    local function esp(p, cr)
        local h = cr:WaitForChild("Humanoid")
        local hrp = cr:WaitForChild("HumanoidRootPart")

        local text = Drawing.new('Text')
        text.Visible = false
        text.Center = true
        text.Outline = true
        text.Color = Color3.new(1, 1, 1)
        text.Font = 2
        text.Size = 13

        local c1 
        local c2
        local c3 

        local function dc()
            text.Visible = false
            text:Remove()
            if c3 then
                c1:Disconnect()
                c2:Disconnect()
                c3:Disconnect()
                c1 = nil 
                c2 = nil
                c3 = nil
            end
        end

        c2 = cr.AncestryChanged:Connect(function(_, parent)
            if not parent then
                dc()
            end
        end)

        c3 = h.HealthChanged:Connect(function(v)
            if (v <= 0) or (h:GetState() == Enum.HumanoidStateType.Dead) then
                dc()
            end
        end)

        c1 = rs.Heartbeat:Connect(function()
            local hrp_pos, hrp_os = c:WorldToViewportPoint(hrp.Position)
            if hrp_os and _G.ESP_ENABLED then
                text.Position = Vector2.new(hrp_pos.X, hrp_pos.Y)
                text.Text = '[ '..tostring(ftool(cr))..' ]'
                text.Visible = true
            else
                text.Visible = false
            end
        end)
    end

    local function p_added(p)
        if p.Character then
            esp(p, p.Character)
        end
        p.CharacterAdded:Connect(function(cr)
            esp(p, cr)
        end)
    end


    local function toggleESP()
        _G.ESP_ENABLED = not _G.ESP_ENABLED
    end


    ps.PlayerAdded:Connect(p_added)


    for _, b in ipairs(ps:GetPlayers()) do 
        if b ~= lp then
            p_added(b)
        end
    end



        local MainTab = Window:CreateTab("Main Tab", nil)
        local FarmTab = Window:CreateTab("Autofarm Tab", nil)
        local VisTab = Window:CreateTab("Visuals Tab", nil)
        local MiscTab = Window:CreateTab("Misc Tab", nil)


        -- [Main Tab] --
        local AimbotToggle = MainTab:CreateToggle({
            Name = "Toggle Aimbot",
            CurrentValue = false,
            Flag = "AimbotToggle", 
            Callback = function(Value)
                local Camera = workspace.CurrentCamera
                local Players = game:GetService("Players")
                local RunService = game:GetService("RunService")
                local UserInputService = game:GetService("UserInputService")
                local TweenService = game:GetService("TweenService")
                local LocalPlayer = Players.LocalPlayer
                local Holding = false

                _G.AimbotEnabled = Value
                _G.TeamCheck = false -- If set to true then the script would only lock your aim at enemy team members.
                _G.AimPart = "Head" -- Where the aimbot script would lock at.
                _G.Sensitivity = 0 -- How many seconds it takes for the aimbot script to officially lock onto the target's aimpart.

                _G.CircleSides = 64 -- How many sides the FOV circle would have.
                _G.CircleColor = Color3.fromRGB(255, 255, 255) -- (RGB) Color that the FOV circle would appear as.
                _G.CircleTransparency = 0.7 -- Transparency of the circle.
                _G.CircleRadius = 80 -- The radius of the circle / FOV.
                _G.CircleFilled = false -- Determines whether or not the circle is filled.
                _G.CircleVisible = true -- Determines whether or not the circle is visible.
                _G.CircleThickness = 0 -- The thickness of the circle.

                if Value == false then
                    _G.CircleVisible = false
                end

                local FOVCircle = Drawing.new("Circle")
                FOVCircle.Position = Vector2.new(Camera.ViewportSize.X / 2, Camera.ViewportSize.Y / 2)
                FOVCircle.Radius = _G.CircleRadius
                FOVCircle.Filled = _G.CircleFilled
                FOVCircle.Color = _G.CircleColor
                FOVCircle.Visible = _G.CircleVisible
                FOVCircle.Radius = _G.CircleRadius
                FOVCircle.Transparency = _G.CircleTransparency
                FOVCircle.NumSides = _G.CircleSides
                FOVCircle.Thickness = _G.CircleThickness

                local function GetClosestPlayer()
                    local MaximumDistance = _G.CircleRadius
                    local Target = nil

                    for _, v in next, Players:GetPlayers() do
                        if v.Name ~= LocalPlayer.Name then
                            if _G.TeamCheck == true then
                                if v.Team ~= LocalPlayer.Team then
                                    if v.Character ~= nil then
                                        if v.Character:FindFirstChild("HumanoidRootPart") ~= nil then
                                            if v.Character:FindFirstChild("Humanoid") ~= nil and v.Character:FindFirstChild("Humanoid").Health ~= 0 then
                                                local ScreenPoint = Camera:WorldToScreenPoint(v.Character:WaitForChild("HumanoidRootPart", math.huge).Position)
                                                local VectorDistance = (Vector2.new(UserInputService:GetMouseLocation().X, UserInputService:GetMouseLocation().Y) - Vector2.new(ScreenPoint.X, ScreenPoint.Y)).Magnitude
                                                
                                                if VectorDistance < MaximumDistance then
                                                    Target = v
                                                end
                                            end
                                        end
                                    end
                                end
                            else
                                if v.Character ~= nil then
                                    if v.Character:FindFirstChild("HumanoidRootPart") ~= nil then
                                        if v.Character:FindFirstChild("Humanoid") ~= nil and v.Character:FindFirstChild("Humanoid").Health ~= 0 then
                                            local ScreenPoint = Camera:WorldToScreenPoint(v.Character:WaitForChild("HumanoidRootPart", math.huge).Position)
                                            local VectorDistance = (Vector2.new(UserInputService:GetMouseLocation().X, UserInputService:GetMouseLocation().Y) - Vector2.new(ScreenPoint.X, ScreenPoint.Y)).Magnitude
                                            
                                            if VectorDistance < MaximumDistance then
                                                Target = v
                                            end
                                        end
                                    end
                                end
                            end
                        end
                    end

                    return Target
                end

                UserInputService.InputBegan:Connect(function(Input)
                    if Input.UserInputType == Enum.UserInputType.MouseButton2 then
                        Holding = true
                    end
                end)

                UserInputService.InputEnded:Connect(function(Input)
                    if Input.UserInputType == Enum.UserInputType.MouseButton2 then
                        Holding = false
                    end
                end)

                RunService.RenderStepped:Connect(function()
                    FOVCircle.Position = Vector2.new(UserInputService:GetMouseLocation().X, UserInputService:GetMouseLocation().Y)
                    FOVCircle.Radius = _G.CircleRadius
                    FOVCircle.Filled = _G.CircleFilled
                    FOVCircle.Color = _G.CircleColor
                    FOVCircle.Visible = _G.CircleVisible
                    FOVCircle.Radius = _G.CircleRadius
                    FOVCircle.Transparency = _G.CircleTransparency
                    FOVCircle.NumSides = _G.CircleSides
                    FOVCircle.Thickness = _G.CircleThickness

                    if Holding == true and _G.AimbotEnabled == true then
                        TweenService:Create(Camera, TweenInfo.new(_G.Sensitivity, Enum.EasingStyle.Sine, Enum.EasingDirection.Out), {CFrame = CFrame.new(Camera.CFrame.Position, GetClosestPlayer().Character[_G.AimPart].Position)}):Play()
                    end
                end)
            end,
         })

         local AimPart = MainTab:CreateDropdown({
            Name = "Aim Part",
            Options = {"Head","HumanoidRootPart"},
            CurrentOption = {"Head"},
            MultipleOptions = false,
            Flag = "AimPart", -- A flag is the identifier for the configuration file, make sure every element has a different flag if you're using configuration saving to ensure no overlaps
            Callback = function(Option)
                local selectedOption
                if type(Option) == "table" then
                    selectedOption = Option[1] -- Extract the first element if it's a table
                else
                    selectedOption = Option -- Use directly if it's already a string
                end
                
                _G.AimPart = selectedOption
            end,
         })

         

        

        local BoxToggle = FarmTab:CreateToggle({
            Name = "Box Job Autofarm",
            CurrentValue = false,
            Flag = "BoxFarm",
            Callback = function(Value)
                local teleport_table = {
                    location1 = Vector3.new(-551.0175170898438, 3.537144184112549, -85.6669692993164), -- start
                    location2 = Vector3.new(-400.960754, 3.41219378, -72.2366257, -0.999820769, -2.88791675e-08, -0.0189329591, -2.808512e-08, 1, -4.22059294e-08, 0.0189329591, -4.1666631e-08, -0.999820769) -- end
                }
                
                local tween_s = game:GetService('TweenService')
                
                local lp = game.Players.LocalPlayer
                
                _G.TELEPORT_ENABLED = Value
                
                function bypass_teleport(v, speed)
                    if lp.Character and lp.Character:FindFirstChild('HumanoidRootPart') then
                        local cf = CFrame.new(v)
                        local distance = (lp.Character.HumanoidRootPart.Position - cf.p).magnitude
                        local baseDuration = 1
                        local duration = baseDuration + (distance / speed)
                        
                        local tweenInfo = TweenInfo.new(duration, Enum.EasingStyle.Linear)
                        local tween = tween_s:Create(lp.Character.HumanoidRootPart, tweenInfo, {CFrame = cf})
                        tween:Play()
                        tween.Completed:Wait() -- Wait for the tween to complete before proceeding
                    end
                end
                
                while _G.TELEPORT_ENABLED do
                    bypass_teleport(teleport_table.location1, 19)
                    wait(1)
                    fireproximityprompt(game:GetService("Workspace").PlaceHere.Attachment.ProximityPrompt)
                    wait(0.5)
                    local crateTool = game.Players.LocalPlayer.Backpack:FindFirstChild("Crate")
                    if crateTool then
                        game.Players.LocalPlayer.Character:WaitForChild("Humanoid"):EquipTool(crateTool)
                    end
                    bypass_teleport(teleport_table.location2, 19)
                    local character = game.Players.LocalPlayer.Character
                    local humanoid = character:WaitForChild("Humanoid")
                    humanoid:Move(Vector3.new(0, 0, -5))
                    wait(1)
                    while game.Players.LocalPlayer.Backpack:FindFirstChild("Crate") or game.Players.LocalPlayer.Character:FindFirstChild("Crate") do
                        fireproximityprompt(game:GetService("Workspace").cratetruck2.Model.ClickBox.ProximityPrompt)
                        wait(1)
                    end
                    wait(1) 
                end                              
            end,
        })
        
        local ATMToggle = FarmTab:CreateToggle({
            Name = "ATM Farm",
            CurrentValue = false,
            Flag = "ATMToggle",
            Callback = function(Value)
                -- Size of the baseplate
local baseplateSize = Vector3.new(10000000, 0, 10000000)  -- Adjust size as needed

-- Get the local player and their character
local player = game.Players.LocalPlayer
local character = player.Character or player.CharacterAdded:Wait()
local humanoidRootPart = character:WaitForChild("HumanoidRootPart")

-- Function to spawn the baseplate under the character's feet
local function SpawnBaseplate()
    -- Calculate baseplate position directly under the character's feet
    local baseplatePosition = humanoidRootPart.Position + Vector3.new(0, -3.3, 0)
    
    -- Create the baseplate
    local baseplate = Instance.new("Part")
    baseplate.Size = baseplateSize
    baseplate.Position = baseplatePosition
    baseplate.Anchored = true
    baseplate.CanCollide = true
    baseplate.Parent = game.Workspace
    
    baseplate.BrickColor = BrickColor.new("Bright blue")  -- Adjust color as desired
    baseplate.Material = Enum.Material.Concrete  -- Adjust material as desired
    
    print("Baseplate spawned under your feet!")
end

-- Call the function to spawn the baseplate when the character is added to the game
game.Players.LocalPlayer.CharacterAdded:Connect(function()
    SpawnBaseplate()
end)

-- Call the function immediately if the character is already in the game
if game.Players.LocalPlayer.Character then
    SpawnBaseplate()
end




                local playerName = game.Players.LocalPlayer.Name
                local lp = game.Players.LocalPlayer
                
                local moneyAmount = game:GetService("Players")[playerName].PlayerGui.Main.Money.Amount
                
                print(moneyAmount.Text)
                
                local moneyValueText = moneyAmount.Text:gsub("%$", "")
                local moneyValue = tonumber(moneyValueText)
                
                local teleport_table = {
                    location1 = Vector3.new(214.934265, 3.73713231, -335.223938),
                    location2 = Vector3.new(-48.807437896728516, 3.735410213470459, -320.9378356933594) 
                }
                
                local hasTeleportedToLocation2 = false
                
                local tween_s = game:GetService('TweenService')
                
                _G.shouldRun = Value -- Toggleable variable
                
                function bypass_teleport(v, speed)
                    if lp.Character and lp.Character:FindFirstChild('HumanoidRootPart') then
                        local cf = CFrame.new(v)
                        local distance = (lp.Character.HumanoidRootPart.Position - cf.p).magnitude
                        local baseDuration = 1
                        local duration = baseDuration + (distance / speed)
                        local tweenInfo = TweenInfo.new(duration, Enum.EasingStyle.Linear)
                        local teleportTween = tween_s:Create(lp.Character.HumanoidRootPart, tweenInfo, {CFrame = cf})
                        teleportTween:Play()
                        teleportTween.Completed:Wait()
                    end
                end
                
                -- Main loop
                while _G.shouldRun do
                    if moneyValue and moneyValue >= 850 then
                        print("Player has more/equal to 850 money")
                        
                        -- Perform teleportation actions
                        bypass_teleport(teleport_table.location1, 19) -- Teleport to location1 with speed 25 studs per second
                        wait(1)  -- Adjust if additional delay is needed after teleporting
                        fireproximityprompt(game:GetService("Workspace").NPCs.FakeIDSeller.UpperTorso.Attachment.ProximityPrompt)
                        wait(1)
                        local fakeID = game.Players.LocalPlayer.Backpack:FindFirstChild("Fake ID")
                        if fakeID then
                            game.Players.LocalPlayer.Character:WaitForChild("Humanoid"):EquipTool(fakeID)
                        end
                        
                        local bankTeller = game:GetService("Workspace").NPCs["Bank Teller"]
                        local proximityPrompt = bankTeller.UpperTorso.Attachment.ProximityPrompt
                        if proximityPrompt then
                            local isActive = false
                            local function CheckPromptActive()
                                isActive = proximityPrompt.Enabled
                                return isActive
                            end
                            repeat
                                wait(0.1)
                            until CheckPromptActive()
                            print("Proximity prompt for Bank Teller is now active")
                            if not hasTeleportedToLocation2 then
                                bypass_teleport(teleport_table.location2, 19) -- Teleport to location2 with speed 25 studs per second
                                hasTeleportedToLocation2 = true 
                            end
                            fireproximityprompt(game:GetService("Workspace").NPCs["Bank Teller"].UpperTorso.Attachment.ProximityPrompt)
                            notif.new({text = 'Requisition | Waiting for card!', duration = 40.2})
                            wait(40.2)
                            print("done")
                            wait(1)
                            bypass_teleport(Vector3.new(-39.2600784, 6.71216249, -330.2117), 19) -- Teleport to another location with speed 25 studs per second
                            fireproximityprompt(game:GetService("Workspace").Blank.Attachment.ProximityPrompt)
                            wait(1)
                            local BlankCard = game.Players.LocalPlayer.Backpack:FindFirstChild("Card")
                            if BlankCard then
                                game.Players.LocalPlayer.Character:WaitForChild("Humanoid"):EquipTool(BlankCard)
                            end
                            local ATMSFolder = game:GetService("Workspace").ATMS
                            local activeATM = nil
                            for _, ATM in pairs(ATMSFolder:GetChildren()) do
                                local proximityPrompt = ATM:FindFirstChild("Attachment") and ATM.Attachment:FindFirstChild("ProximityPrompt")
                                if proximityPrompt and proximityPrompt.Enabled then
                                    activeATM = ATM
                                    break
                                end
                            end
                            if activeATM then
                                local ATMHeightOffset = 3  -- Adjust this value as needed to place it above the ATM
                                local targetPosition = activeATM.Position + Vector3.new(0, ATMHeightOffset, 0)
                                print("Teleporting to ATM at position:", targetPosition)
                                bypass_teleport(targetPosition, 19) -- Teleport to ATM location with speed 25 studs per second
                                local character = game.Players.LocalPlayer.Character
                                local humanoid = character:WaitForChild("Humanoid")
                                humanoid:Move(Vector3.new(0, 0, -5))
                                wait(1)
                                fireproximityprompt(activeATM:WaitForChild("Attachment"):WaitForChild("ProximityPrompt"))
                                if iswindowactive() then
                                    mousemoveabs(game:GetService("Players").LocalPlayer.PlayerGui:WaitForChild("ATM").Frame.Swipe.AbsolutePosition.X + 250,game:GetService("Players").LocalPlayer.PlayerGui.ATM.Frame.Swipe.AbsolutePosition.Y + 80)
                                    mousemoverel(1,1)
                                    task.wait(.1)
                                    mouse1click()
                                else
                                    notif.new({text = 'Requisition | Roblox not focussed', duration = 4})
                                end
                            else
                                print("No active ATM found")
                            end
                        else
                            print("Proximity prompt for Bank Teller not found")
                        end
                    else
                        print("Player does not have enough money")
                    end
                    hasTeleportedToLocation2 = false
                    wait(8) -- Repeat the loop every 5 seconds
                end                 
            end,
        })


        -- [Visuals Tab] --
        loadstring(game:HttpGet("https://raw.githubusercontent.com/Iratethisname10/Code/main/espLibrary.lua"))()
        local espLibrary = getgenv().espLibrary
        espLibrary.Visuals.BoxSettings.Type = 2
        
        local ESPToggle = VisTab:CreateToggle({
            Name = "Toggle ESP",
            CurrentValue = false,
            Flag = "ESPT", 
            Callback = function(Value)
                espLibrary.Settings.Enabled = Value
            end,
         })
        local BoxToggle = VisTab:CreateToggle({
            Name = "Toggle Boxes",
            CurrentValue = false,
            Flag = "BOXT", 
            Callback = function(Value)
                espLibrary.Visuals.BoxSettings.Enabled = Value
            end,
         })
        local FilledToggle = VisTab:CreateToggle({
            Name = "Filled Boxes",
            CurrentValue = false,
            Flag = "FilledT", 
            Callback = function(Value)
                espLibrary.Visuals.BoxSettings.Filled = Value
            end,
         })
        local HBToggle = VisTab:CreateToggle({
            Name = "Health Bar",
            CurrentValue = false,
            Flag = "HBT", 
            Callback = function(Value)
                espLibrary.Visuals.HealthBarSettings.Enabled = Value
            end,
         })


        local TextSection = VisTab:CreateSection("Other ESP")

        local ATMToggle = VisTab:CreateToggle({
            Name = "Active ATM ESP",
            CurrentValue = false,
            Flag = "ActiveATMESP",
            Callback = function(Value)
                local ATMSFolder = game:GetService("Workspace").ATMS
                local activeATMs = {}
                _G.TextVisible = Value -- Initially not visible

                -- Function to create or update the text drawing object for an ATM
                local function updateTextDrawing(atm)
                    if not _G.TextVisible then return end -- Check if text visibility is disabled

                    if activeATMs[atm] then
                        activeATMs[atm]:Remove()
                    end
                    
                    local text = "ATM Active"
                    local textDrawing = Drawing.new("Text")
                    textDrawing.Text = text
                    textDrawing.Size = 20
                    textDrawing.Color = Color3.fromRGB(255, 255, 255)
                    
                    local viewportPosition = game:GetService("Workspace").CurrentCamera:WorldToViewportPoint(atm.Position)
                    textDrawing.Position = Vector2.new(viewportPosition.X, viewportPosition.Y) -- Convert to Vector2
                    textDrawing.Visible = true
                    activeATMs[atm] = textDrawing
                end

                -- Function to check for active ATMs and update text drawings
                local function updateActiveATMs()
                    if not _G.TextVisible then
                        for _, textDrawing in pairs(activeATMs) do
                            textDrawing:Remove() -- Remove all text drawings
                        end
                        activeATMs = {} -- Clear the table
                        return
                    end

                    for _, ATM in pairs(ATMSFolder:GetChildren()) do
                        local proximityPrompt = ATM:FindFirstChild("Attachment") and ATM.Attachment:FindFirstChild("ProximityPrompt")
                        if proximityPrompt and proximityPrompt.Enabled then
                            updateTextDrawing(ATM)
                        elseif activeATMs[ATM] then
                            activeATMs[ATM]:Remove()
                            activeATMs[ATM] = nil
                        end
                    end
                end

                -- Call the function initially and set up a loop to continuously check for active ATMs
                updateActiveATMs()
                game:GetService("RunService").Stepped:Connect(function()
                    updateActiveATMs()
                end)
 
            end,
        })

        local Button = VisTab:CreateButton({
            Name = "Show Guns",
            Callback = function()
                loadstring(game:HttpGet("https://raw.githubusercontent.com/hellmid122/script-0x391/main/guns"))()
            -- The function that takes place when the button is pressed
            end,
         })


        -- [Misc Tab] --
        local IPButton = MiscTab:CreateButton({
            Name = "Instant Proximity",
            Callback = function()
                for i,v in ipairs(game:GetService("Workspace"):GetDescendants()) do
                    if v.ClassName == "ProximityPrompt" then
                     v.HoldDuration = 0
                    end
                   end                   
            end,
         })

        local SmallButton = MiscTab:CreateButton({
            Name = "Join smallest server",
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
            end,
         })

         
         local RejoinButton = MiscTab:CreateButton({
            Name = "Rejoin server",
            Callback = function()
                local ts = game:GetService("TeleportService")
                local p = game:GetService("Players").LocalPlayer
                ts:Teleport(game.PlaceId, p)        
            end,
         })

         local HopButton = MiscTab:CreateButton({
            Name = "Server Hop",
            Callback = function()
                local module = loadstring(game:HttpGet"https://raw.githubusercontent.com/LeoKholYt/roblox/main/lk_serverhop.lua")()
                module:Teleport(game.PlaceId)     
            end,
         })

         local AntiIdle = MiscTab:CreateButton({
            Name = "Anti Idle",
            Callback = function()
                local Players = game:GetService("Players")
                local GC = getconnections or get_signal_cons
                if GC then
                    for i, v in pairs(GC(Players.LocalPlayer.Idled)) do
                        if v["Disable"] then
                            v["Disable"](v)
                        elseif v["Disconnect"] then
                            v["Disconnect"](v)
                        end
                    end
                else
                    local VirtualUser = game:GetService("VirtualUser")
                    Players.LocalPlayer.Idled:Connect(function()
                        VirtualUser:CaptureController()
                        VirtualUser:ClickButton2(Vector2.new())
                    end)
                end
            end,
        })

        local Section = MiscTab:CreateSection("Auto Kick")

        local kickamt = 0

        local Input = MiscTab:CreateInput({
            Name = "Player Kick Amount",
            PlaceholderText = "# of Players",
            RemoveTextAfterFocusLost = false,
            Callback = function(Text)
                kickamt = tonumber(Text)
            end,
        })
        
        local Toggle = MiscTab:CreateToggle({
            Name = "Auto Kick Toggle",
            CurrentValue = false,
            Flag = "Toggle1", -- A flag is the identifier for the configuration file, make sure every element has a different flag if you're using configuration saving to ensure no overlaps
            Callback = function(Value)
                local Players = game:GetService("Players")
        
                local function checkPlayerCount()
                    local playerCount = #Players:GetPlayers()
                    print("Number of players in the game: " .. playerCount)
                    
                    if playerCount >= kickamt then
                        print("Equal to or more than 5")
                        -- Add your logic here if you want to kick players based on kickamt
                        -- For example, print kickamt value
                        print("Kick amount set to: " .. (kickamt or "not set"))
                    end
                end
                
                while Value do
                    wait(2)
                    checkPlayerCount()
                end
            end,
        })

        local player = game.Players.LocalPlayer
        local HitboxEnabled3 = false

        local function adjustHitbox(player)
            print("Adjusting hitbox for player:", player.Name)
            if player.Character then
                local head = player.Character:FindFirstChild("Head")
                if head then
                    if HitboxEnabled3 then
                        pcall(function()
                            head.Size = Vector3.new(2.3, 2.3, 2.3)
                            head.Transparency = 0.9
                            head.BrickColor = BrickColor.new("Glass")
                            head.Material = "Glass"
                            head.CanCollide = false
                        end)
                    else
                        pcall(function()
                            head.Size = Vector3.new(0, 0, 0)
                            head.Transparency = 0
                            head.BrickColor = BrickColor.new("Glass")
                            head.Material = "Glass"
                            head.CanCollide = true
                        end)
                    end
                end
            end
        end

        local function applyHitboxStateToAllPlayers3()
            for _, otherPlayer in ipairs(game.Players:GetPlayers()) do
                if otherPlayer ~= player then
                    adjustHitbox(otherPlayer)
                end
            end
        end

    
        local function onPlayerAdded(player)
            print("Player added:", player.Name)
            player.CharacterAdded:Connect(function(character)
                wait(1) 
                adjustHitbox(player)
            end)
        end

        local function onPlayerRespawn(player)
            print("Player respawned:", player.Name)
            player.CharacterAdded:Connect(function(character)
                character:WaitForChild("Humanoid").Died:Connect(function()
                    wait(35)
                    adjustHitbox(player)
                end)
            end)
        end

        
        applyHitboxStateToAllPlayers3()

        
        game.Players.PlayerAdded:Connect(onPlayerAdded)
        print("Player added event connected")

        game.Players.PlayerAdded:Connect(function(player)
            onPlayerAdded(player)
            player.CharacterAdded:Connect(function(character)
                wait(1) 
                adjustHitbox(player)
            end)
        end)
        print("Player added and respawn events connected")

    
        


        
        


        




        local Toggle = MainTab:CreateToggle({
            Name = "Silent Aim (TESTING)",
            CurrentValue = false,
            Flag = "semiLegit", 
            Callback = function(Value)
                HitboxEnabled3 = Value 
                applyHitboxStateToAllPlayers3() 
            end,
        })
